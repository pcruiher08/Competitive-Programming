import math

def factor(n):
    pos=[2,3]
    pos.extend([6*k+i for k in range(1,math.ceil(n/12)+1) for i in [-1,1]])
    pos.append(n)
    primes=[]
    exponents=[]
    iter=0
    while(n>1):
        if(n%pos[iter]==0):
            primes.append(pos[iter])
            ex=0
            while(n%pos[iter]==0):
                n=n/pos[iter]
                ex+=1
            exponents.append(ex)
        iter+=1
    return [primes,exponents]

n = int(input())

primes, exponents = factor(n)
print(exponents)

ans1 = 1

for p in primes:
    ans1 *= p

exp = 0
allArePowerOfTwo = True

for e in exponents:
    exp |= e
    if str(bin(e)[2:]).count("1") != 1:
        allArePowerOfTwo = False

print(bin(exp))


calculateMaxPow2 = 

if(max(exponents) > 1):
    calculateMaxPow2 = math.ceil(math.log(exp, 2)) + 1

ans2 = calculateMaxPow2 + allArePowerOfTwo

if(n == 1):
    print("1 0")
else:
    print(ans1, ans2)