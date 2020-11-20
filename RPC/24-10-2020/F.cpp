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

class Graph{
   int V;
   list< pii > *adj;

public:
   Graph(int V); // Constructor
   void addEdge(int u, int v, int w);
   vector<int> Dijkstra(int s);
};

Graph::Graph(int V){
   this->V = V;
   adj = new list<pii > [V];
}

void Graph::addEdge(int u, int v, int w){
   //cambiar si son dirigidos
   adj[u].pb(mp(v, w));
   //adj[v].pb(mp(u, w));
}



// imprime todos los caminos mas cortos desde un origen hacia todos los nodos
vector<int> Graph::Dijkstra(int src){
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

struct coord{

    int x,y;
};

int main(){


int n, k; cin>>n>>k; 

vector<vector<coord> > adj(51*51);

FOR(i,0,n,1)
    FOR(j,0,n,1){
    int lec; cin>>lec; 
    //coord i,j
    coord aux; 
    aux.x=i;
    aux.y=j;
    //cout<<"lec: "<<lec<<", x: "<<aux.x<<", y: "<<aux.y<<" \n";
    adj[lec].pb(aux);
    //cout<<lec<<endl;

    //FOR(k,0,adj[lec-1].size(),1)cout<<adj[lec-1][k].x<<", "<<adj[lec-1][k].y<<" ";
    //cout<<endl;
}

FOR(i,1,k+1,1){
    if(adj[i].size()==0){
        cout<<-1<<endl;
        return 0;

    }

}

//cout<<"me sali \n";

Graph g(k+1);

/*

FOR(i,1,k+1,1){
    //cout<<i<<" -> ";
    FOR(j,0,adj[i].size(),1){
        //cout<<adj[i][j].x<<" "<<adj[i][j].y<<" "<<j<<", ";
        //cout<<i<<","<<i+1<<","<<abs(adj[i][j].x - adj[i+1][j].x) + abs(adj[i][j].y - adj[i+1][j].y)<<" ";
        //g.addEdge(i,i+1,abs(adj[i][j].x - adj[i+1][j].x) + abs(adj[i][j].y - adj[i+1][j].y));
    }
    //cout<<endl;
}
*/
FOR(i,1,k+1,1){
    //cout<<i<<" -> ";
    FOR(j,0,adj[i].size(),1){
        //cout<<adj[i][j].x<<" "<<adj[i][j].y<<", ";
        FOR(k,0,adj[i+1].size(),1){
            if(abs(adj[i][j].x - adj[i+1][k].x) + abs(adj[i][j].y - adj[i+1][k].y) == 1){
                cout<<i<<","<<i+1<<","<<abs(adj[i][j].x - adj[i+1][k].x) + abs(adj[i][j].y - adj[i+1][k].y)<<","<<k<<"; ";
            }
            g.addEdge(i,i+1,abs(adj[i][j].x - adj[i+1][k].x) + abs(adj[i][j].y - adj[i+1][k].y));
        }
    }
    cout<<endl;
}
//cout<<"empieza"<<endl;
vector<int> res = g.Dijkstra(1);
FOR(i,1,k+1,1)cout<<res[i]<<endl;

return 0;
}


/*
3 3
1 2 3
3 2 1
3 1 2


*/