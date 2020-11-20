n = int(input())
num = 3
lista = [3]*3
while(len(lista) < n):
    num += 3
    newLista = [num]*num

    lista.extend(newLista)

for i in range(n):
    print(lista[i], end=' ')
