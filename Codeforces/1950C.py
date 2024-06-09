n = int(input())

while(n):
    n = n - 1
    lec = input()
    hora, minutos = lec.split(':')
    hora = int(hora)
    minutos = int(minutos)
    meridiano = "PM" if (hora >= 12) else "AM"

    hora = hora % 12

    if(hora == 0):
        hora = 12

    if(hora < 10):
        hora = '0'+str(hora)

    if(minutos < 10):
        minutos = '0'+str(minutos)

    print(f"{hora}:{minutos} {meridiano}")
