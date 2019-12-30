f1 = 1
f2 = 1
cuenta = 1
while len(str(f1))<1000:
    cuenta = cuenta + 1
    a = f1
    f1 = f2
    f2 = a + f2

print(cuenta)
print(f1)
