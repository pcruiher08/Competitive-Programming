import sys as archivo

archivo.stdin = open("input.txt", "r")
archivo.stdout = open("output.txt", "w")


n = int(input())

listas = {}

lec = list(map(int, input().split()))


cuenta = 0

for num in lec:
    cuenta += 1

    if(num not in listas):
        listavacia = list()
        listas[num] = listavacia
    listas[num].append(cuenta)


#checar que todos aparezcan una cantidad par de veces

if( any(len(listaN) % 2 != 0 for listaN in listas.values()) ):
    print(-1)

else:
    for listaN in listas.values():
        contador = 0
        while(contador < len(listaN) - 1):
            print(listaN[contador], listaN[contador + 1])
            contador += 2
