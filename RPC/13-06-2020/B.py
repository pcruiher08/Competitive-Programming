from collections import Counter as contador
(n,k) = map(int,input().split())
arregloSol = []
for i in range(n):
   arregloSol.append(int(input()))
cuentaDerecha = contador(arregloSol)
cuentaIzquierda = contador()
solucion = []
for indexActual in arregloSol:
    cuentaDerecha[indexActual] -= 1
    if(cuentaIzquierda[indexActual]):
        continue
    while(len(solucion) and solucion[len(solucion)-1] > indexActual and (cuentaIzquierda[solucion[len(solucion)-1]] > 1 or cuentaDerecha[solucion[len(solucion)-1]])):
        cuentaIzquierda[solucion.pop()] -= 1
    solucion.append(indexActual)
    cuentaIzquierda[indexActual] += 1
while(len(solucion) and cuentaIzquierda[solucion[-1]] > 1):
    cuentaIzquierda[solucion.pop()] -= 1
print(" ".join(map(str,solucion)))   