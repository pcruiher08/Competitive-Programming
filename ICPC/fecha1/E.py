
from itertools import permutations

def isPrime(n):  
    if (n <= 1): 
        return False
    if (n <= 3): 
        return True
    if (n % 2 == 0 or n % 3 == 0): 
        return False
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0): 
            return False
        i = i + 6
  
    return True

def recorre(nums):
    #print(nums)
    for num in nums:
        lenOfNum = len(num)
        num = int(num)
        if len(str(num)) == lenOfNum:
            if isPrime(num):
                #print(num)
                return num
    return 0


k = input()

posibles = []
for s in [''.join(j) for j in permutations(k)]:

    for i in range(1,len(s)):
        for j in range(i+1,len(s)):
            parte1 = s[0:i]
            parte2 = s[i:j]
            parte3 = s[j:len(s)]

            primero = recorre(sorted([''.join(p) for p in permutations(parte1)]))
            segundo = recorre(sorted([''.join(p) for p in permutations(parte2)]))
            tercero = recorre(sorted([''.join(p) for p in permutations(parte3)]))
            if(primero and segundo and tercero):
                posibles.append(primero*segundo*tercero)

posibles = sorted(posibles)
if len(posibles):
    print(posibles[0])
else:
    print("Bob lies")