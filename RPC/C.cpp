#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int time, cost;
    Node() : time(0), cost(0) {}
    Node(int t, int c) : time(t), cost(c) {}
};


void solve(int remaining_time, int current_cost, int edge_cost, int curr_node, int &min_cost, const vector< vector<int> >& graph, const vector<Node>& node_list, int times[], int costs[]){
    if (curr_node == 0 && remaining_time == 0 && (min_cost == -1 || current_cost < min_cost)) min_cost = current_cost;
    else if (remaining_time - times[curr_node] >= 0 && (min_cost == -1 || current_cost < min_cost)) {
        if (remaining_time - times[curr_node] >= 0 && (min_cost == -1 || current_cost + node_list[curr_node].cost < min_cost))
            solve(remaining_time - node_list[curr_node].time, current_cost + node_list[curr_node].cost, edge_cost, curr_node, min_cost, graph, node_list, times, costs);
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int node = graph[curr_node][i];
            if (remaining_time - times[node] >= 0 && (min_cost == -1 || current_cost + node_list[node].cost < min_cost))
                solve(remaining_time - node_list[node].time - edge_cost, current_cost + node_list[node].cost, edge_cost, node, min_cost, graph, node_list, times, costs);
        }
    }
}

struct State {
    int curr_node, time_elapsed, cost;
    State(int c, int t, int p) : curr_node(c), time_elapsed(t), cost(p) {}
};

int main() {
    int time, nodes, edges, edge_time, total_cost = 0;
    cin >> time >> nodes >> edges >> edge_time;
    vector< vector<int> > graph(nodes);
    vector< Node > node_list;
    
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < nodes; i++) {
        int t, p;
        cin >> t >> p;
        node_list.push_back(Node(t, p));
    }

    bool visited[nodes];
    int times[nodes];
    int costs[nodes];
    times[0] = node_list[0].time;
    for (int i = 0; i < nodes; i++) visited[i] = false;
    queue<State> bfs_q;
    bfs_q.push(State(0, node_list[0].time, node_list[0].cost));
    visited[0] = true;
    times[0] = 0;
    costs[0] = 0;
    while (!bfs_q.empty()) {
        State curr = bfs_q.front();
        bfs_q.pop();
        int curr_node = curr.curr_node;
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int node = graph[curr_node][i];
            if (!visited[node]) {
                visited[node] = true;
                times[node] = curr.time_elapsed + edge_time;
                costs[node] = curr.cost;
                bfs_q.push(State(node, curr.time_elapsed + edge_time + node_list[node].time, curr.cost + node_list[node].cost));
            }
        }   
    }

    // for (int i = 0; i < nodes; i++) cout << "costo de 1 a " << i + 1 << " : " << costs[i] << endl;
    // for (int i = 0; i < nodes; i++) cout << "tiempo de 1 a " << i + 1 << " : " << times[i] << endl;


    if (time - 2 * node_list[0].time > 0) {
        int min_c = -1;
        solve(time - node_list[0].time , total_cost + node_list[0].cost, edge_time, 0, min_c, graph, node_list, times, costs);
        if (min_c != -1) cout << min_c << endl;
        else cout << "It is a trap." << endl;
    } else {
        cout << "It is a trap." << endl;
    }
}

