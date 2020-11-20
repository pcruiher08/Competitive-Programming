#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

struct compareString {
    bool operator() (string a, string b) {
        if (a.size() == b.size()) return a > b;
        return a.size() > b.size();
    }
};

typedef priority_queue<string, vector<string>, compareString> minheap;

int find(vector<int> &C, int x) {
    return (C[x] == x) ? x : C[x] = find(C, C[x]);
}

int merge(vector<int> &C, int x, int y) {
    int new_pos = find(C, y);
    C[find(C, x)] = new_pos;
    return new_pos;
}

int main() {
    vector<int> C(100000, 0);
    int n;
    string u, v, line;
    cin >> n;

    int last = 0;
    map<string, int> index;
    stack<pair<int, int>> merges;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        int u_set, v_set;
        auto u_it = index.find(u);
        if (u_it == index.end()){
            last++;
            index[u] = last;
            C[last] = last;
        }
        auto v_it = index.find(v);
        if (v_it == index.end()) {
            last++;
            index[v] = last;
            C[last] = last;
        }

        index[u] = index[v] = merge(C, index[u], index[v]);
    }

    for (auto &p: index) index[p.first] = find(C, p.second);
    map<int, minheap> heaps;

    for (auto &p: index) {
        int set_no = p.second;
        string key = p.first;
        if (heaps.find(set_no) != heaps.end()) {
            heaps[set_no].push(key);
        } else {
            minheap heap;
            heap.push(key);
            heaps[set_no] = heap;
        }
    }

    cin.ignore();
    getline(cin, line);
    stringstream ss(line);
    string token;
    vector<string> words;
    while(!ss.eof()) {
        ss >> token;
        words.push_back(token);
    }

    for (int i = 0; i < words.size(); i++) {
        auto it = index.find(words[i]);
        if (it == index.end()) cout << words[i];
        else cout << heaps[it->second].top();

        cout << ((i == words.size() - 1) ? "\n" : " ");
    }
}