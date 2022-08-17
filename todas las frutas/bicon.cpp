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
#define vvi vector<vi>
#define pii pair<int,int>
using namespace std;

int n, m, ans, ticks;
vvi conecta;
vvi tr;
vi num, bajo, comp;
vector<pii> puentes;
stack<int> st;
int cp;
vector<int> cutPoints;
int ncmp;

void findBiconCompsDFS(int x, int p) {
	st.push(x);
	bajo[x] = num[x] = ++ticks;
    FOR(i,0,conecta[x].size(),1){
		int nx = conecta[x][i];
		if(nx == p) continue;
		if(!(num[nx] + 1)) {
			findBiconCompsDFS(nx, x);
			if(bajo[nx] > num[x]) puentes.pb(mp(x,nx));
			if(p!=-1 && bajo[nx] >= num[x]) cp = 1;
			if(p==-1 && rch>1) cp = 1;
			bajo[x] = min(bajo[x], bajo[nx]);
		} else 
			bajo[x] = min(bajo[x], num[nx]);
	}
	if(cp) cutPoints.pb(x);
	
	if(bajo[x]==num[x]) {
		++ncmp;
		while(!st.empty()) {
			int y = st.top();
			st.pop();
			comp[y] = ncmp;
			if(y==x) break;
		}
	}
}

int main() {
	int T, tc = 0;
    cin>>T;
	while(T--) {
        cin>>n>>m;
		conecta.assign(n + 1, vi());
		num.assign(n+1,-1);
		bajo.assign(n+1,-1);
		comp.assign(n+1,-1);
		puentes.clear();
		ncmp = 0;
		ticks = 0;
		while(!st.empty())
			st.pop();
		FOR(i,0,m,1){
			int x, y;
            cin>>x>>y;
			conecta[x].pb(y);
			conecta[y].pb(x);
		}
		findBiconCompsDFS(0,-1);
		
		tr.assign(ncmp+1,vi());
        FOR(i,0,puentes.size(),1){
			pii &b = puentes[i];
			tr[comp[b.first]].pb(comp[b.second]);
			tr[comp[b.second]].pb(comp[b.first]);
		}
        
	}
	return 0;
}