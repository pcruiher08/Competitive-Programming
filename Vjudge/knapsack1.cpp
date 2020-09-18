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
#define max(a,b) a>b?a:b
using namespace std;

int main(){
sync;

int n,w; cin>>n>>w;
int artic[n];
int pesos[n];
FOR(i,1,n+1,1)cin>>artic[i]>>pesos[i];
int mochila[n+1][w+1]; FOR(i,1,n+1,1)FOR(j,1,w+1,1)mochila[i][j] = 0;

FOR(i,1,n+1,1)FOR(j,1,w+1,1){
    int aux = mochila[i-1][j];
    mochila[i][j] = (j<pesos[j])?aux:max(aux,artic[i]+mochila[i-1][j-pesos[i]]);
}

cout<<mochila[n][w]<<endl;

return 0;
}