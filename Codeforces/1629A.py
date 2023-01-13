from typing import List

def max_ram(n: int, k: int, a: List[int], b: List[int]) -> int:
    memo = [0] * (k + 1)
    for i in range(1, k+1):
        memo[i] = i
    for i in range(n):
        for j in range(k, 0, -1):
            if j >= a[i]:
                memo[j] = max(memo[j], memo[j-b[i]]+b[i])
    return memo[k]

def max_ram_greedy(n: int, k: int, a: List[int], b: List[int]) -> int:
    software = list(zip(a, b)).sort()
    for a,b in software:
        if a<=k:k += b
    return k
    


t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ab = list(zip(a,b))
    ab.sort()
    for a, b in ab:
        if a <= k:k += b
    print(k)




