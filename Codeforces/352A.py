n=int(input())
num = input().replace(' ','')

l = []

if(n - int(num.count('5'))):
    print(int('5'*(int(num.count('5'))-int(num.count('5'))%9) + '0'*(n - int(num.count('5')))))
else:
    print(-1)