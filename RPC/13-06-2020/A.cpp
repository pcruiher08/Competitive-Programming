#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    vi taxes(n);
    vi accums(n, 0);
    vector<vi> matrix(n, vi(n, -1));
    vector<vi> check(n, vi(n, 0));
    for (int i = 0; i < n; i++) cin >> taxes[i];

    int from, to, toll;
    for (int i = 0; i < n - 1; i++) {
        cin >> from >> to >> toll;
        from--;
        to--;
        matrix[from][to] = toll;
        matrix[to][from] = toll;
    }

    for (int k  = 0; k < n; k++) {
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    if (matrix[i][k] > 0 && matrix[k][j] > 0) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }

    for (int i = 0 ; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                accums[i] += matrix[i][j] * (taxes[i] + taxes[j]);
                accums[j] += matrix[i][j] * (taxes[i] + taxes[j]);
            }
        }

    for (int i = 0; i < n; i++) {
        cout << accums[i] << endl;
    }

}