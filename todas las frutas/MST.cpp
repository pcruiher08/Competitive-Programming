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

#define vertices 10


void PRIM(int grafo[vertices][vertices]){
    int parent[vertices];
    int llave[vertices];
    bool seti[vertices];

    FOR(i,0,vertices,1){llave[i] = INF; seti[i] = 0;}
 
    llave[0] = 0;
    parent[0] = -1;
    FOR(count,0,vertices-1,1){

        int minimo = INF;
        int minindex;
        FOR(i,0,vertices,1){
            if(!seti[i] && llave[i] < minimo){
                minimo = llave[i];
                minindex = i;
            }
        } 
        int u = minindex;
        seti[u] = 1;
        FOR(v,0,vertices,1)
            if((grafo[u][v] && seti[v] == false) && (grafo[u][v] < llave[v])){
                parent[v] = u;
                llave[v] = grafo[u][v];
            }
    }
 
    FOR(i,1,vertices,1) cout<<"edge: "<<parent[i] << " -> " << i << " (" << grafo[i][parent[i]] << ")" << endl;
}


int main(){
sync;

int grafo[vertices][vertices] ={{ 0, 1, 15, 0, 23, 0, 24, 25, 0, 16 },
                                { 1, 0, 22, 10, 11, 9, 27, 8, 0, 2 },
                                { 15, 22, 0, 0, 12, 26, 7, 28, 0, 0 },
                                { 0, 10, 0, 0, 20, 21, 29, 14, 19, 0 },
                                { 23, 11, 12, 20, 0, 6, 5, 4, 0, 0 },
                                { 0, 9, 26, 21, 6, 0, 30, 13, 0, 18 },
                                { 24, 27, 7, 29, 5, 30, 0, 0, 0, 0 },
                                { 25, 8, 28, 14, 4, 13, 0, 0, 0, 17 },
                                { 0, 0, 0, 19, 0, 0, 0, 0, 0, 3 },
                                { 16, 2, 0, 0, 0, 18, 0, 17, 3, 0 }
                                
                                 };

FOR(i,0,vertices,1){
    FOR(j,i,vertices,1){
        if(grafo[i][j]){
            //cout<<"g.addEdge("<<i<<","<<j<<","<<grafo[i][j]<<")"<<endl;
        }
        //cout<<grafo[i][j]<<" ";
    }//cout<<endl;
}


PRIM(grafo);


return 0;
}