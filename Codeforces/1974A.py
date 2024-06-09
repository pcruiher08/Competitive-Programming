def sol(x, y):
    b = (y + 1) // 2
    postb = 15 * b - y * 4
    
    a = x - postb
    if a < 0:
        a = 0

    prea = (a + 14) // 15
    total_screens = b + prea
    return total_screens


t = int(input())
results = []

for i in range(t):
    x, y = map(int, input().split())
    results.append(sol(x, y))


for result in results:
    print(result)
