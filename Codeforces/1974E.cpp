#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Opportunity {
    int cost;
    int happiness;
};

int maxHappiness(int m, int x, vector<Opportunity>& opportunities) {
    vector<vector<int>> dp(m + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= m; ++i) {
        int c = opportunities[i - 1].cost;
        int h = opportunities[i - 1].happiness;
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j]; // initialize with the previous month's happiness

            if (j >= c) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c] + h); // consider spending money to gain happiness
            }
        }
    }

    return dp[m][x];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m, x;
        cin >> m >> x;

        vector<Opportunity> opportunities(m);
        for (int i = 0; i < m; ++i) {
            cin >> opportunities[i].cost >> opportunities[i].happiness;
        }

        // Adjust initialization of DP table to reflect Charlie starting with no money
        vector<vector<int>> dp(m + 1, vector<int>(x + 1, 0));

        int result = maxHappiness(m, x, opportunities);
        cout << result << endl;
    }

    return 0;
}
