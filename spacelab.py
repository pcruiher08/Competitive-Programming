'''
# Dado una matriz de datos de tamaño n, se te solicita escribir un programa en Python que imprima los
# caracteres a lo largo de los perímetros de la matriz, comenzando desde el perímetro exterior y avanzando
# hacia los perímetros internos hasta llegar al centro de la matriz.

1 2  3  4
5 6  7  8
9 10 11 12
13 14 15 16

#n  horizontal
#m vertical

'''




def espiral(mat, i, j, n, m):

    if(i >= n or j >= m):
        return
    
    for k in range(n):
        print(mat[i][j + k])

    for k in range(1, n):
        print(mat[i + k][m - j - 1])
    
    for k in range(1, n):
        print(mat[n - i - 1][m - j - k - 1]) 

    for k in range(1, n - 1):
        print(mat[n - i - k - 1][j])

    espiral(mat, i + 1, j + 1, n - 1, m - 1)

mat = [
    ['a', 'b', 'c', 'd'],
    ['l', 'm', 'n', 'e'],
    ['k', 'p', 'o', 'f'],
    ['j', 'i', 'h', 'g'],
]

espiral(mat, 0, 0, 4, 4)

    
