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

char maze[1011][1011];
bool visitados[1011][1011];

bool isinbounds(pair<int,int> p, int n, int m){
    int x = p.first;
    int y = p.second;
    if(x >= 0 && x < n && y >= 0 && y < m){
        if(maze[x][y] == '.'){
            return true;
        }
    }

    return false;
}


int main(){
sync;
int n, m; cin>>n>>m;
vector<pair<int, int> > toolook;
FOR(i,0,n,1)FOR(j,0,m,1){
    cin>>maze[i][j];
    visitados[i][j] = 0;
    if(maze[i][j] == '.'){
        toolook.push_back({i,j});
    }
}

stack<char> s;


int res = 0;
for(auto casilla : toolook){
    int i = casilla.first;
    int j = casilla.second;
    if((visitados[i][j] == 0) && maze[i][j] == '.'){
        res++;
        //bfs para marcar islas
        queue<pair<int, int> > q;
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(visitados[x][y] == 0){
                visitados[x][y] = 1;
                if(isinbounds({x + 1, y}, n, m)){
                    q.push({x + 1, y});
                }
                if(isinbounds({x, y + 1}, n, m)){
                    q.push({x, y + 1});
                }
                if(isinbounds({x - 1,y}, n, m)){
                    q.push({x - 1, y});
                }
                if(isinbounds({x, y - 1}, n, m)){
                    q.push({x, y - 1});
                }
            }
        }
    }
}


cout<<res<<endl;
return 0;
}