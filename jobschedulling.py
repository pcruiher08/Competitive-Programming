def jobScheduling(orderedDeadlines, orderedProfits, n, maxDeadline):
    DP = [[0 for i in range(n)] for j in range(maxDeadline - 1)]
    for i in range(n):
        for j in range(orderedDeadlines[n - 1]):
            ti = orderedDeadlines[i] - j
            if ti < 0:
                DP[i][j] = 0
            else:
                DP[i][j] = DP[i - 1][j]
            DP[i][j] = max(DP[i - 1][j], orderedProfits[j] + DP[i - ti][j])
    return DP[n - 1][maxDeadline - 2]

