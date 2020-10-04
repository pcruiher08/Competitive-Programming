archProblema = input()
nombreArch = input()
lenguajesPermitidos = set(["java","py","cpp","c"])
if not "." in nombreArch:
    print("Compile Error")
    quit()

envioDivididoP = nombreArch.split(".")
if len(envioDivididoP) != 2:
    print("Compile Error")
    quit()

envioB = envioDivididoP[0]
archEnvio = envioDivididoP[-1]

if envioB != archProblema:
    print("Compile Error")
    quit()

if not archEnvio in lenguajesPermitidos:
    print("Compile Error")
    quit()

flag, tiempo, cuantoTarda = map(int,input().split())

if flag:
    print("Run-Time Error")
    quit()

if cuantoTarda > tiempo:
    print("Time Limit Exceeded")
    quit()

lineasCorrectas = int(input())

correct = []
for i in range(0, lineasCorrectas):
    correct.append(input())

lineasEnviadas = int(input())
if lineasEnviadas is not lineasCorrectas:
    print("Wrong Answer")
    quit()

for i in range(0, lineasCorrectas):
    envio = input()
    if envio != correct[i]:
        print("Wrong Answer")
        quit()

print("Correct")

