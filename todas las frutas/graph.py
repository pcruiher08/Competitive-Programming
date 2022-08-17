# coding: utf-8
# by Joao Bueno
from random import randrange, choice
import pygame
 
FR = 30
SIZE = 640, 480
BGCOLOR = (255,255,255)
NODECOLOR = (255,0,0)
NODESIZE = 10,10
GRIDSPACING = 50
MAXTRIES = 1000
STARTINGNODES = 8
 
class Graph(object):
    def __init__(self):
        self.nodes = set()
        # record positions of each node, so that we can check for overlaps
        self.positions = dict()
 
    def add(self, node):
        count = 0
        added = False
        # try to add node at some random location -
        # change the algorithm to suit your needs:
        while not added:
            x, y = (randrange(0, SIZE[0], GRIDSPACING),
                        randrange(0, SIZE[1], GRIDSPACING))
            if not (x,y) in self.positions:
                added = True
                self.nodes.add(node)
                node.setpos((x,y), self)
            count += 1
            if count >= MAXTRIES:
                raise ValueError("Could not alocate space for node representation")
 
    def update(self):
        SCREEN.fill(BGCOLOR)
        for node in self.nodes:
            pygame.draw.rect(SCREEN, node.color, node.rect)
            for neighbor in node.neighbors:
                pygame.draw.line(SCREEN, NODECOLOR,
                    node.rect.center, neighbor.rect.center)
 
class Node(object):
    # Class variable, incremented with each
    # instance so that each node has a unique ID that
    # can be used as its hash:
    creation_counter = 0
    def __init__(self):
        self.id = self.__class__.creation_counter
        self.__class__.creation_counter += 1
        # We don't  set this attribute here, but by adding then here,
        # we indicate that it "exists" for readers of the code:
        self.rect = None
        self.color = NODECOLOR
        self.neighbors = set()
 
    def setpos(self, pos, graph = None):
        if self.rect and graph:
            # remove self from previous position in the graph:
            graph.positions.pop(self.rect.topleft, None)
        self.rect = pygame.Rect(pos[0], pos[1],NODESIZE[0], NODESIZE[1])
        if graph:
            graph.positions[pos] = self
 
    def  __hash__(self):
        return self.id
 
 
def create_graph():
    # create new graph and populate nodes:
    graph = Graph()
    # locallist for adding neighbors:
    nodes = []
    for i in range(STARTINGNODES):
        node = Node()
        graph.add(node)
        # randomly connect node with some other nodes
        if nodes:
            for i in range(0, randrange(1,3)):
                neighbor = choice(nodes)
                # Without a special collection, or an "Edge" class,
                # in adirectional graphs, we should always upddate
                # neighbor set in both nodes:
                node.neighbors.add(neighbor)
                neighbor.neighbors.add(node)
        nodes.append(node)
    return graph
 
def init():
    global SCREEN
    pygame.init()
    SCREEN = pygame.display.set_mode(SIZE)
 
def quit():
    pygame.quit()
 
def main():
    graph = create_graph()
    # Putting the "pygame.quit" call in a try-finally clause
    # will guarrantee Pygame exits normally if later you
    # decide to use fullscreen graphics
    selected = None
    try:
        init()
        while True:
            graph.update()
            pygame.event.pump()
            # Exit the mainloop at any time the "ESC" key is pressed
            if pygame.key.get_pressed()[pygame.K_ESCAPE]:
                break
            for event in pygame.event.get():
                if event.type == pygame.MOUSEBUTTONDOWN:
                    x, y = event.pos
                    # round down x,y to multiples of NODESIZE
                    x -= x % NODESIZE[0]
                    y -= y % NODESIZE[1]
                    pygame.draw.rect(SCREEN, (0,0,255), (x,y) + NODESIZE)
                    if (x,y) in graph.positions:
                        node = graph.positions[x,y]
                        if selected:
                            print(selected.id, node.id)
                            if selected is node:
                                selected = None
                                node.color = NODECOLOR
                            elif selected not in node.neighbors:
                                selected.neighbors.add(node)
                                node.neighbors.add(selected)
                            else:
                                selected.neighbors.remove(node)
                                node.neighbors.remove(selected)
                        else:
                            node.color = (0,0,0)
                            selected = node
                    elif selected:
                        selected.setpos((x,y), graph)
                elif event.type == pygame.MOUSEMOTION and event.buttons[0] and selected:
                    x, y = event.pos
                    # round down x,y to multiples of NODESIZE
                    x -= x % NODESIZE[0]
                    y -= y % NODESIZE[1]
                    selected.setpos((x,y), graph)
 
            pygame.display.flip()
            pygame.time.delay(FR)
    finally:
        quit()
 
# Pattern in Python to make the same module
# be reusable as  main program or importable module:
# if the builtin "__name__" variable is set to "__main__"
# this is the main module, and should perform some action
# (otherwise it is set to the module name)
if __name__ == "__main__":
    main()