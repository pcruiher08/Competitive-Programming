num = 1

print(str(num)[-1] + str(num)[:-1])
lenactual = 2

while(True):
    if(2 * num == int(str(num)[-1] + str(num)[:-1])):
        print(num)
    num += 1
    if(len(str(num))!=lenactual):
        lenactual += 1
        print(num)



