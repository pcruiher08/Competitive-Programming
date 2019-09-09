import math

[x, y, msum] = list(map(int, input().split()))
total = 0
nums = 0
for i in range(1, msum + 1):
    factors = []
    rev = []
    for j in range(1, int(math.sqrt(i) + 1)):
        if i % j == 0:
            factors.append(j)
            if j * j != i:
                rev.append(i // j)
    rev.reverse()
    for j in rev:
        factors.append(j)
    available = 0
    for j in factors:
        if j > min(x, y):
            break
        available += 1
    initAvailable = available
    for j in factors[:-initAvailable-1:-1]:
        if j > max(x, y):
            available -= 1
    maxMult = (msum - total) // i
    nums += min(maxMult, available)
    total += min(maxMult, available) * i
    if maxMult < available:
        break
print(nums)
