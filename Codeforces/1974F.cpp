#include <iostream>
#include <vector>
using namespace std;

pair<int, int> count_points(int a, int b, vector<pair<int, int>>& chips, vector<pair<char, int>>& moves) {
    int rows_remaining = a;
    int cols_remaining = b;
    int points_alice = 0;
    int points_bob = 0;

    for (auto& chip : chips) {
        int x = chip.first;
        int y = chip.second;
        if (x <= rows_remaining && y <= cols_remaining) {
            points_alice++;
        } else {
            points_bob++;
        }
    }

    for (auto& move : moves) {
        char direction = move.first;
        int k = move.second;
        if (direction == 'U' || direction == 'D') {
            points_alice += k * cols_remaining;
            rows_remaining -= k;
        } else if (direction == 'L' || direction == 'R') {
            points_alice += k * rows_remaining;
            cols_remaining -= k;
        }
    }

    points_bob = chips.size() - points_alice;
    return make_pair(points_alice, points_bob);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        vector<pair<int, int>> chips(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            chips[i] = make_pair(x, y);
        }
        vector<pair<char, int>> moves(m);
        for (int i = 0; i < m; i++) {
            char direction;
            int k;
            cin >> direction >> k;
            moves[i] = make_pair(direction, k);
        }
        auto result = count_points(a, b, chips, moves);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
