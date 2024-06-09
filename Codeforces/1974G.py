def max_happiness(t, cases):
    for case in cases:
        m, x = case[0], case[1]
        costs = case[2]
        max_happy = 0
        for i in range(m):
            units = min(x // costs[i], 1)
            max_happy += units
            x -= units * costs[i]
        print(max_happy)

# Input
t = int(input())
cases = []
for _ in range(t):
    m, x = map(int, input().split())
    costs = list(map(int, input().split()))
    cases.append((m, x, costs))

# Output
max_happiness(t, cases)
