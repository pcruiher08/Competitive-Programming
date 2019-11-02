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

int C[100001], adj[100001], num[100001];
//disjoint set
ull find(int element){
    if(adj[element] == element)return element;
    return adj[element] = find(adj[element]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(num[a] < num[b])swap(a, b);
        if(C[a] > C[b])C[a] = C[b];
        adj[b] = a;
        if (num[a] == num[b])num[a]++;
    }
}

    
 
int main(){ 
sync;
int n,m;
cin>>n>>m;
ull cuenta = 0;
FOR(i,1,n+1,1){
    cin>>C[i];
    adj[i] = i;
}

int u, v;
FOR(i,1,m+1,1){
    cin>>u>>v;
    merge(u, v);
}

FOR(i,1,n+1,1){
    if (find(i)==i)cuenta+=C[i];
}

cout<<cuenta<<endl;

return 0;
}