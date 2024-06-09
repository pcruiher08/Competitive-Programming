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
    
    for k in range(i, m):
        print(mat[i][k])

    for k in range(i + 1, n):
        print(mat[k][m - 1])

    if((n - 1) != i):
        for k in range(m - 2, j - 1, - 1):
            print(mat[n - 1][k]) 

    if((m - 1) != i):
        for k in range(n - 2, i, -1):
            print(mat[k][j])

    espiral(mat, i + 1, j + 1, n - 1, m - 1)

mat = [
    ['a', 'b', 'c', 'd'],
    ['l', 'm', 'n', 'e'],
    ['k', 'p', 'o', 'f'],
    ['j', 'i', 'h', 'g']
]

mat2 = [
    ['a', 'b', 'c', 'd', 'e'],
    ['p', 'q', 'r', 's', 'f'],
    ['o', 'x', 'y', 't', 'g'],
    ['n', 'w', 'v', 'u', 'h'],
    ['m', 'l', 'k', 'j', 'i']
]

mat3 = [
    ['1', '2', '3', '4', '5', '6'],
    ['16', '17', '18', '19', '20', '7'],
    ['15', '24', '23', '22', '21', '8'],
    ['14', '13', '12', '11', '10', '9'],
]


mat4 = [
    ['1', '2', '3', '4', '5', '6']
]

mat5 = [
    ['1'],
    ['2'],
    ['3'],
    ['4'],
    ['5']
]

mat6 = [
    ['1']
]

#hace falta solo cambiar la matriz en la siguiente linea para probar los casos de prueba que hice
matrix = mat3

espiral(matrix, 0, 0, len(matrix), len(matrix[0]))

    
