class Node:

    def __init__(self, state, parent, operation):
        self.state = state
        self.parent = parent
        self.operation = operation

    def __str__(self):
        if (self.parent == None):
            return f"{self.state}\n"

        return f"{self.parent} Apply operation {self.operation} to {self.parent.state} and get {self.state}\n"

        
    def getState(self):
        return self.state
    
    def getParent(self):
        return self.parent

    def getOperation(self):
        return self.operation

class State:

    def __init__(self, missionaries, cannibals, boatPosition):
        self.missionaries = missionaries
        self.cannibals = cannibals

        # the only valid positions for boat are 0 and 1, where 0 represents right side and 1 represents left side
        self.boatPosition = boatPosition
    
    def __eq__(self, other):
        if(isinstance(other, State)):
            return self.missionaries == other.missionaries and self.cannibals == other.cannibals and self.boatPosition == other.boatPosition
    
    def __str__(self):
        return f"State: ({self.missionaries}, {self.cannibals}, {self.boatPosition})"
 
    def setMissionaries(self, missionaries):
        self.missionaries = missionaries
    
    def setCannibals(self, cannibals):
        self.cannibals = cannibals
        
    def setBoatPosition(self, boatPosition):
        self.boatPosition = boatPosition
    
    def getMissionaries(self):
        return self.missionaries
        
    def getCannibals(self):
        return self.cannibals

    def getBoatPosition(self):
        return self.boatPosition

    def getRightSideMissionaries(self):
        return initialMissionaries - self.missionaries
    
    def getRightSideCannibals(self):
        return initialCannibals - self.cannibals

operationMapping = {"1M":[1,0,1], "1C":[0,1,1], "2M":[2,0,1], "2C":[0,2,1], "1M1C":[1,1,1]}


def applyOpperation(state, operation):
    # sum = 1
    # substraction = 0
    newMissionariesAmmount = 0
    newCannibalsAmmount = 0
    newBoatPosition = 0

    sumOrSubstraction = not state.getBoatPosition()

    if sumOrSubstraction:
        newMissionariesAmmount = state.getMissionaries() + operationMapping[operation][0]
        newCannibalsAmmount = state.getCannibals() + operationMapping[operation][1]
        newBoatPosition = state.getBoatPosition() + operationMapping[operation][2]
    else:
        newMissionariesAmmount = state.getMissionaries() - operationMapping[operation][0]
        newCannibalsAmmount = state.getCannibals() - operationMapping[operation][1]
        newBoatPosition = state.getBoatPosition() - operationMapping[operation][2]

    return State(newMissionariesAmmount, newCannibalsAmmount, newBoatPosition)
    

def isStateValid(state):
    isValid = True
    #negative state case on left side
    if state.getMissionaries() < 0 or state.getCannibals() < 0:
        isValid = False
    #super positive state case on left side
    if state.getMissionaries() > initialMissionaries or state.getCannibals() >  initialCannibals:
        isValid = False

    #cannibals eat missionaries on left side case
    if state.getMissionaries() < state.getCannibals() and state.getMissionaries() != 0:
        isValid = False

    #negative state case on right side
    if state.getRightSideMissionaries() < 0 or state.getRightSideCannibals() < 0:
        isValid = False
    #super positive state case on right side
    if state.getRightSideMissionaries() > initialMissionaries or state.getRightSideCannibals() >  initialCannibals:
        isValid = False

    #cannibals eat missionaries on right side case
    if state.getRightSideMissionaries() < state.getRightSideCannibals() and state.getRightSideMissionaries() != 0:
        isValid = False

    return isValid  
    

## 1M   -> 1,0,1
## 1C   -> 0,1,1
## 2M   -> 2,0,1
## 2C   -> 0,2,1
## 1M1C -> 1,1,1


initialMissionaries = 3
initialCannibals = 3


def bfs(state):
    visited = []
    queue = []
    goal = State(0,0,0)

    actualNode = Node(state, None, "Start")

    queue.append(actualNode)

    while(len(queue) != 0):

        actualNode = queue[0]
        queue.pop(0)

        if actualNode.getState() in visited:
            continue

        visited.append(actualNode.getState())

        if actualNode.getState() == goal:
            return actualNode
        
        for operation in operationMapping:
            newState = applyOpperation(actualNode.getState(), operation)
            if isStateValid(newState) and not (newState in visited):
                newNode = Node(newState, actualNode, operation)
                queue.append(newNode)

    return None


def dfs(state):
    visited = []
    queue = []
    goal = State(0,0,0)

    actualNode = Node(state, None, "Start")

    queue.append(actualNode)

    while(len(queue) != 0):

        actualNode = queue[-1]
        queue.pop()

        if actualNode.getState() in visited:
            continue

        visited.append(actualNode.getState())

        if actualNode.getState() == goal:
            return actualNode
        
        for operation in operationMapping:
            newState = applyOpperation(actualNode.getState(), operation)
            if isStateValid(newState) and not (newState in visited):
                newNode = Node(newState, actualNode, operation)
                queue.append(newNode)

    return None


inicio = State(3,3,1)

print("With BFS")
path = bfs(inicio)

if path != None:
    print(path)
else:
    print("No path found")


print("With DFS")
path = dfs(inicio)

if path != None:
    print(path)
else:
    print("No path found")



