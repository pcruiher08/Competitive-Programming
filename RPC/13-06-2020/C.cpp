// PENDING

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;

struct state {
    int min_changes;
    int node;
    state() : min_changes(0), node(0)  {}
    state(int m, int n) : min_changes(m), node(n)  {}
};


int main() {
    int n, m, a, b;

    cin >> n >> m;

    vector<vi> edges(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    vi visit(n);
    visit.assign(n, -1);
    queue<state> bfsq;

    for (auto e : edges[0]) {
        bfsq.push(state(0, e));
        visit[e] = 0;
    }
    
    while (!bfsq.empty()) {
        state curr = bfsq.front();
        bfsq.pop();

        if (curr.node == n - 1) continue;
        for (auto e : edges[curr.node]) {
             if (visit[e] == - 1 || curr.min_changes + 1 < visit[e]) {
                 visit[e] = curr.min_changes + 1;
                 bfsq.push(state(visit[e], e));
             }
        }
    }

    cout << visit[n - 1] << endl;
}