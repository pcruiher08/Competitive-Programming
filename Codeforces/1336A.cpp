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

vector<int> adj[300000];
bool visitados[300000];

int cuentaDFS(int node, int anterior, vector<int> &paths){
    visitados[node] = 1;
	int siguiente = 0;
    for(int i = 0; i < adj[node].size(); i++){
		if(!visitados[adj[node][i]]){
			siguiente += cuentaDFS(adj[node][i], anterior+1, paths);
        }
	}
	paths.pb(anterior-siguiente);
	return siguiente + 1;
}

int main()
{

    sync;

    int n, k; cin>>n>>k;

	
    for(int i = 0; i < n - 1; i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);

    }

	vector<int> paths;
    cuentaDFS(1,0,paths);
    sort(paths.begin(), paths.end());
    ll res = 0; 

    FOR(j,0,k,1){
        res += paths[paths.size() - j - 1]; 
    }

   
    cout<<res<<endl;

	return 0;
}
