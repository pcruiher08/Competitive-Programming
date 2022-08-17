letter = ord("0")

def printParentheses(i, j, n, parentheses):
    global letter

    if i == j:
        print("M"+chr(letter),end="", sep="")
        letter += 1
        return

    print("(", end="")
    printParentheses(i, parentheses[i][j], n, parentheses)
    printParentheses(parentheses[i][j] + 1, j, n, parentheses)
    print(")", end="")


def matrixMult(p):
    n = len(p)
    DP = [[0 for i in range(n)] for j in range(n)]
    parentheses = [[0 for i in range(n)] for j in range(n)]

    
    for tam in range(2, n):
        for i in range(1, n - tam + 1):
            j = i + tam - 1
            DP[i][j] = 10e9+7

            for k in range(i, j):
                minimum = DP[i][k] + DP[k+1][j] + p[i-1]*p[k]*p[j]
                if minimum < DP[i][j]:
                    DP[i][j] = minimum
                    parentheses[i][j] = k
                    
            for x in range(1,n):
                for y in range(1,n):
                    print(DP[x][y], end="\t")
                print()
            print()

    for x in range(1,n):
        for y in range(1,n):
            print(parentheses[x][y], end="\t")
        print()
    print()
    printParentheses(1,n-1,n,parentheses)
    print()
    return DP[1][n-1]

p = [20, 8, 3, 27, 8, 11]
print(matrixMult(p))