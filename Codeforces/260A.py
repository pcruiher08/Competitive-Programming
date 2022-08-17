def arbol(a,nActual,n,b):
    for i in range(0,10):
        nuevoNumero=10*a+i
        if(nuevoNumero % b==0):
            return str(nuevoNumero) + "0"*(n-1)
    
    return -1

 
[a,b,n]=[int(i) for i in input().split()]
print(arbol(a,0,n,b))