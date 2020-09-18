edades = []



s = "hola"

while s!='EXIT':
    try:
        s = input()
        if(s=='EXIT'):
            break
        edades.append(int(s))



print(edades)