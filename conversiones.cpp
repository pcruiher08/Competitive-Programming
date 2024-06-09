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

int main(){
sync;

/*

8
1 2
1 3
3 2
3 4
4 5
5 6
6 1
7 1

*/
int n;
cin>>n;


vector<vector<pair<int, double>> > adj(n);
//id, value

for(int i = 0; i < n; i++){
    int a, b; cin>>a>>b;
    double c; cin>>c;
    adj[a].push_back({b, c});
}


//hay camino de x a y?
int x, y; cin>>x>>y;
int visitados[n];
memset(visitados, 0, sizeof(visitados));
queue<int> q;
q.push(x);

bool encontrado = false;

while(!q.empty()){

    int actual = q.front();
    q.pop();

    if(actual == y){
        cout<<"YES"<<endl;
        encontrado = 1;
        break;
    }
    
    if(visitados[actual] == 0){
        visitados[actual] = 1;
        for(int i = 0; i < adj[actual].size(); i++){
            q.push(adj[actual][i]);
        }
    }
}

if(!encontrado){
    cout<<"NO"<<endl;
}

return 0;
}