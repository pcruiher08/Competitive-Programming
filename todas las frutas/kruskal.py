from collections import defaultdict
 
def sortFunc(x):
    return x[2]

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []
 
    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])
 
    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])
 
    def union(self, parent, rank, firstP, secondP):
        firstProot = self.find(parent, firstP)
        secondProot = self.find(parent, secondP)
 
        if rank[firstProot] < rank[secondProot]:
            parent[firstProot] = secondProot
        elif rank[firstProot] > rank[secondProot]:
            parent[secondProot] = firstProot
        else:
            parent[secondProot] = firstProot
            rank[firstProot] += 1

    def sortFunc(x):
        return x[2]

    def KruskalMST(self):
        self.graph = sorted(self.graph, key=sortFunc)
        parent = []
        rank = []
        group = []
        count = 0
        rev = 0
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
 
        while rev + 1 < self.V:
            u, v, w = self.graph[count]
            count += 1
            firstP = self.find(parent, u)
            secondP = self.find(parent, v)

            if firstP != secondP:
                rev += 1
                group.append([u, v, w])
                self.union(parent, rank, firstP, secondP)
 
        minimumCost = 0
        for u, v, weight in group:
            minimumCost += weight
            print("edge: %d -> %d (%d)" % (u, v, weight))
 
g = Graph(10)
g.addEdge(1,0,1)
g.addEdge(2,0,15)
g.addEdge(4,0,23)
g.addEdge(6,0,24)
g.addEdge(7,0,25)
g.addEdge(9,0,16)
g.addEdge(2,1,22)
g.addEdge(3,1,10)
g.addEdge(4,1,11)
g.addEdge(5,1,9)
g.addEdge(6,1,27)
g.addEdge(7,1,8)
g.addEdge(9,1,2)
g.addEdge(4,2,12)
g.addEdge(5,2,26)
g.addEdge(6,2,7)
g.addEdge(7,2,28)
g.addEdge(4,3,20)
g.addEdge(5,3,21)
g.addEdge(6,3,29)
g.addEdge(7,3,14)
g.addEdge(8,3,19)
g.addEdge(5,4,6)
g.addEdge(6,4,5)
g.addEdge(7,4,4)
g.addEdge(6,5,30)
g.addEdge(7,5,13)
g.addEdge(9,5,18)
g.addEdge(9,7,17)
g.addEdge(9,8,3)

g.KruskalMST()

Carlos Garcia A01196981
Pablo C Ruiz A01197044