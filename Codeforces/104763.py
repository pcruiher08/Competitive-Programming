def cuenta(n):
    n = bin(n).count('1')
    return n

n = int(input())
s = int(input(), 2)

uno = ""
dos = ""

for i in range(n):
    if(i % 2 == 0):
        uno+='1'
        dos+='0'
    else:
        uno+='0'
        dos+='1'

uno = int(uno, 2)
dos = int(dos, 2)

uno = uno ^ s
dos = dos ^ s

uno = cuenta(uno)
dos = cuenta(dos)

if(uno < dos):
    print(uno)
else:
    print(dos)
