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
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

class Graph{
	int V;
	list< pii > *adj;

public:
	Graph(int V); // Constructor
	void addEdge(int u, int v, int w);
	vector<int> shortestPath(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<pii > [V];
}

void Graph::addEdge(int u, int v, int w){
    //cambiar si son dirigidos
	adj[u].pb(mp(v, w));
	adj[v].pb(mp(u, w));
}

// imprime todos los caminos mas cortos desde un origen hacia todos los nodos
vector<int> Graph::shortestPath(int src){
	priority_queue< pii, vector <pii > , greater<pii > > pq;
	vector<int> dist(V, INF);
	//se ingresa el origen con distancia 0 hacia si mismo
	pq.push(mp(0, src));
	dist[src] = 0;
	vector<bool> visitados(V, false);
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		visitados[u] = true;
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i){
			int v = (*i).first;
			int weight = (*i).second;
			if (visitados[v] == false && dist[v] > dist[u] + weight){
				dist[v] = dist[u] + weight;
				pq.push(mp(dist[v], v));
			}
		}
	}
	return dist;
}

int main(){
sync;
	int V = 9;
	Graph g(V);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
    vector<int> distancias(V);
	distancias = g.shortestPath(0);
    FOR(i,0,V,1)cout<<i<<" "<<distancias[i]<<endl;
	return 0;

return 0;
}