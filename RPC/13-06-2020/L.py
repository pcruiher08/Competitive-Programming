def raiz(palabra):
    respuesta = []
    for i in range(len(palabra)*2 - 1):
        respuesta.append(0)
    for primero in range(len(palabra)):
        for segundo in range(len(palabra)):
            respuesta[primero+segundo] = respuesta[primero+segundo] + int(palabra[primero]) * int(palabra[segundo])
            respuesta[primero+segundo] = respuesta[primero+segundo] % 10
    final = "".join(map(str, respuesta))
    return final

def procesa(palabra):
    global s
    aux = raiz(palabra)
    if aux == s:
        return palabra
    if len(aux) >= len(s):
        return
    if aux[:len(palabra)] != s[:len(palabra)]:
        return
    for i in range(25):
        aux2 = procesa(palabra + str(i))
        if(aux2):
            return aux2
    return


s = input()

posible = ""

res = procesa(posible)

if(res):
    print(res)
else:
    print(-1)
