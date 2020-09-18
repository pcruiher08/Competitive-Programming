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

int H,W; cin>>H>>W;
char matriz[H+1][W+1];

FOR(i,1,H+1,1)FOR(j,1,W+1,1)cin>>matriz[i][j];
ll caminos[H+1][W+1];
FOR(i,0,H+1,1)FOR(j,0,W+1,1)caminos[i][j]=0;

FOR(i,1,H+1,1)FOR(j,1,W+1,1){
    if(matriz[i][j]=='#')goto salta;
    caminos[i][j] = (i==1&&j==1)?1:MOD(caminos[i-1][j] + caminos[i][j-1]);
    salta :;
}

cout<<caminos[H][W]<<endl;
return 0;
}