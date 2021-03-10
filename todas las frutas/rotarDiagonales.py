def gira(m):
    n=len(m[0])
    for i in range(n//2):
        for j in range(i,n-i-1):
            aux = m[i][j]
            m[i][j] = m[n-1-j][i]
            m[n-1-j][i] = m[n-1-i][n-1-j]
            m[n-1-i][n-1-j]=m[j][n-1-i]
            m[j][n-1-i]=aux



def rotateOverDiagonals(m,k):
    len(m[0])
    diagonalPrincipal = [m[i][i] for i in range(len(m[0]))]
    diagonalSecundaria = [m[len(m[0])-1-i][i] for i in range(len(m[0])-1,-1,-1)]
    
    for i in range(k):
        gira(m)
        for i in range(len(m[0])):
            m[i][i] = diagonalPrincipal[i]
            m[len(m[0])-1-i][i] = diagonalSecundaria[len(m[0]) - i - 1]


m = [[1, 2, 3, 4, 5],
     [6, 7, 8, 9, 10],
     [11, 12, 13, 14, 15],
     [16, 17, 18, 19, 20],
     [21, 22, 23, 24, 25]]

rotateOverDiagonals(m,1)
print(m)