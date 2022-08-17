//
// Created by Sisu on 2/20/2016.
//

/*
 * Scheduling: Suppose you have one machine and n jobs, a1; :::; an. Each job aj has processing time tj , prot pj ,
 * and deadline dj . The machine can only process one job at a time and that job must run uninterruptedly until
 * completion. If job aj is completed by deadline dj , you receive prot pj , but if it is completed after, you
 * receive nothing. Assuming all processing times are integers between 1 and n and dj  tj for all jobs, give an
 * algorithm for computing the maximum profit you can make.
 */

#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;
struct job {
    int time;
    int deadline;
    int profit;
};

class Solution {
public:
    /*
     * assume input jobs are already sorted by deadlines
     */
    std::vector<job> jobScheduling(const std::vector<job>& input) {
        /*
         * dp[i][j], from jobs in [0, i], until time j, maximum profit we can make
         * dp[i][j] = max{ dp[i-1][j], dp[i-1][j-ti] + pi }, if j <= di, else just dp[i-1][j]
         */
        std::vector<job> result;
        if (input.empty()) { return result; }

        int N = input.size(), D = input[input.size()-1].deadline;

        bool track[N][D+1];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= D; ++j) {
                track[i][j] = false;
            }
        }

        int dp[N][D+1];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= D; ++j) {
                if (i == 0) {
                    dp[i][j] = (j < input[i].time) ? 0 : input[i].profit;
                    track[i][j] = (j >= input[i].time);
                } else if (j < input[i].time || j > input[i].deadline) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    int val = dp[i-1][j-input[i].time] + input[i].profit;
                    dp[i][j] = std::max(dp[i-1][j], val);
                    track[i][j] = (val > dp[i-1][j]);
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= D; ++j) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        

        int i = N-1, j = D;
        while (i >= 0 && j >= 0) {
            if (track[i][j]) {
                result.push_back(input[i]);
                j -= input[i].time;
            }
            i -= 1;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<job>> tests = {
            { // empty test
            },
            { // can only select one job
                    { .time = 1, .deadline = 2, .profit = 10 }
                    , { .time = 2, .deadline = 2, .profit = 11 }
            },
            { // should pick all of them
                    { .time = 1, .deadline = 3, .profit = 1 }
                    , { .time = 1, .deadline = 3, .profit = 1 }
                    , { .time = 1, .deadline = 3, .profit = 1 }
            },
            { // should pick none
                    { .time = 3, .deadline = 1, .profit = 1 }
                    , { .time = 3, .deadline = 1, .profit = 1 }
            },
            { // mixed case
                    { .time = 3, .deadline = 4, .profit = 3 }
                    , { .time = 3, .deadline = 5, .profit = 1 }
                    , { .time = 2, .deadline = 6, .profit = 3 }
            },
            {

                
                {.time = 9, .deadline = 1, .profit = 10 },
                {.time = 1, .deadline = 5, .profit = 80 },
                 {.time = 5, .deadline = 9, .profit = 10 },
                 {.time = 5, .deadline = 10, .profit = 30 },
                {.time = 8, .deadline = 11, .profit = 15 }
               
            }
    };

    for (auto const& test : tests) {
        std::cout << std::endl << std::endl << "input: " << std::endl;
        for (auto const& item : test) {
            std::cout << "  (t:" << item.time << ", d:" << item.deadline << ", p:" << item.profit << ")" << std::endl;
        }
        std::cout << "result: " << std::endl;
        for (auto const& item : sol.jobScheduling(test)) {
            std::cout << "  (t:" << item.time << ", d:" << item.deadline << ", p:" << item.profit << ")" << std::endl;
        }
    }

    return 0;
}