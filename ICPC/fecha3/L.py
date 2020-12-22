def enlarge(s):
    return s+s

num = int(input())
arr = input().split(' ')
arr2 = arr

for i in range(num):
    arr2[i] = enlarge(arr2[i])

cuenta = 0

for i in range(num):
    for j in range(num):
        if(arr[j].find(arr[i]) and j != i):
            cuenta += 1

print(cuenta)