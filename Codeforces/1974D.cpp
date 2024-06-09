#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;


// Function to solve the problem
vector<string> distributeInstructions(int t, vector<pair<int, string>>& testCases) {
    vector<string> results;
    for (int i = 0; i < t; ++i) {
        int n = testCases[i].first;
        string instructions = testCases[i].second;

        // Counting the occurrences of each instruction
        int count_N = 0, count_S = 0, count_E = 0, count_W = 0;
        for (char c : instructions) {
            if (c == 'N') count_N++;
            else if (c == 'S') count_S++;
            else if (c == 'E') count_E++;
            else if (c == 'W') count_W++;
        }

        // Calculating the net movement
        int net_x = count_E - count_W;
        int net_y = count_N - count_S;

        // Check if both devices can reach the same point after adjusting instructions
        if ((net_x % 2 == 0 && net_y % 2 == 0) || (n > 1 && (net_x % 2 != 0 || net_y % 2 != 0))) {
            string result = "";
            bool roverExecuted = false;
            for (char instruction : instructions) {
                if (instruction == 'N' || instruction == 'S') {
                    if (!roverExecuted) {
                        result += 'R';
                        roverExecuted = true;
                    } else {
                        result += (net_y > 0) ? 'R' : 'H';
                        net_y -= 1;
                    }
                } else if (instruction == 'E' || instruction == 'W') {
                    if (!roverExecuted) {
                        result += 'R';
                        roverExecuted = true;
                    } else {
                        result += (net_x > 0) ? 'R' : 'H';
                        net_x -= 1;
                    }
                }
            }
            results.push_back(result);
        } else {
            // If adjustment is not possible, output 'NO'
            results.push_back("NO");
        }
    }
    return results;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    vector<pair<int, string>> testCases;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n; // Number of instructions
        string instructions;
        cin >> instructions; // Sequence of instructions
        testCases.push_back(make_pair(n, instructions));
    }

    // Output
    vector<string> results = distributeInstructions(t, testCases);
    for (string result : results) {
        cout << result << endl;
    }

    return 0;
}
