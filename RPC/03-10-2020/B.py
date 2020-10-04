a,b,c = [int(x) for x in input().split()]
rep = 0

for i in range(a,b+1):
    rep += str(i).count(str(c))

print(rep)