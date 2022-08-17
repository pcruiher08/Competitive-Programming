def calc(X, Y):
    m = len(X)
    n = len(Y)
    DP = [[ [0,""] for a in range(n + 1)] for b in range(m + 1)]
    for i in range(1, m + 1):
        DP[i][0][0] = i

    for j in range(1, n + 1):
        DP[0][j][0] = j

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            a = DP[i-1][j][0] + 1
            b = DP[i][j-1][0] + 1
            c = DP[i-1][j-1][0] + (1 if X[i - 1] != Y[j - 1] else 0)

            operation = "deletion"
            lastOperation = ""
            if a <= b and a <= c:
                operation = "deletion"
                lastOperation = DP[i-1][j][1]
            if b <= a and b <= c:
                opreation = "insertion"
                lastOperation = DP[i-1][j][1]
            if c <= a and c <= b:
                if X[i - 1] == Y[j - 1]:
                    operation = ""
                else:
                    operation = "change"
                lastOperation = DP[i-1][j][1]


            DP[i][j] = (min(a,b,c),lastOperation + " " + operation) 

    return DP[m][n]
    

X = 'pablo'
Y = 'carlos'

print(calc(X, Y))