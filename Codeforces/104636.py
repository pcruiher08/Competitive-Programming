n = input()
lec = list(map(int, input().split()))

mini = min(lec)
maxi = max(lec)

resta = lec.count(mini) + lec.count(maxi)

if(mini != maxi):

    print(len(lec) - resta)

else:
    print(0)
