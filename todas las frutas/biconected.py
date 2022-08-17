from collections import defaultdict
  
class grafo:
    def __init__(self, vertices):
        self.V = vertices
        self.grafo = defaultdict(list)
        self.tick = 0
        self.count = 0

    def addEdge(self, u, v):
        self.grafo[u].append(v)
        self.grafo[v].append(u)

    def DFSFind(self, u, ancestro, bajo, disc, stack):
        hijos = 0
        disc[u] = self.tick
        bajo[u] = self.tick
        self.tick += 1
        for v in self.grafo[u]:
            if disc[v] == -1 :
                ancestro[v] = u
                hijos += 1
                stack.append((u, v))
                self.DFSFind(v, ancestro, bajo, disc, stack)
                bajo[u] = min(bajo[u], bajo[v])
                if ancestro[u] == -1 and hijos > 1 or ancestro[u] != -1 and bajo[v] >= disc[u]:
                    self.count += 1
                    w = -1
                    while w!=(u, v):
                        w = stack.pop()
                        print(str(w[0])+"<->"+str(w[1]),end=" ")
                    print()
            elif v != ancestro[u] and bajo[u] > disc[v]:
                bajo[u] = min(bajo [u], disc[v])
                stack.append((u, v))

    def biconnected(self):
        disc = [-1] * (self.V)
        bajo = [-1] * (self.V)
        ancestro = [-1] * (self.V)
        stack = []
 
        for i in range(self.V):
            if disc[i] == -1:
                self.DFSFind(i, ancestro, bajo, disc, stack)
            if stack:
                self.count = self.count + 1
                while stack:
                    w = stack.pop()
                    print(str(w[0])+"<->"+str(w[1]),end=" ")
                print ()
 
 
g = grafo(11)
g.addEdge(1, 2)
g.addEdge(2, 3)
g.addEdge(1, 3)
g.addEdge(2, 5)
g.addEdge(2, 4)
g.addEdge(4, 5)
g.addEdge(4, 6)
g.addEdge(7, 6)
g.addEdge(6, 10)
g.addEdge(6, 9)
g.addEdge(6, 8)
g.addEdge(7, 8)
g.addEdge(8, 9)
g.addEdge(9, 10)
g.addEdge(9, 0)
g.biconnected()