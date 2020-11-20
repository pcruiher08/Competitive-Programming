numbers = list(map(int, input().split()))
numbers.sort()
#print(numbers)
maximo = 0
for i in range(3):
    for j in range(3):
        for k in range(3):
            if(i!=j and i!=k and j!=k):
                maximo = max(maximo, int((numbers[i]+numbers[j])*numbers[k]*0.5))
                #print(maximo,numbers[i],numbers[j],numbers[k])
print(maximo)