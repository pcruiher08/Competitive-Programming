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

int t; cin>>t; 
while(t--){
    int n,m,res = 0; cin>>n>>m; 
    int arr[n+1][m+1];
    FOR(i,1,n+1,1)FOR(j,1,m+1,1)cin>>arr[i][j];
    int DP[n+m+1][2];
    FOR(i,0,n+m+1,1)FOR(j,0,2,1)DP[i][j] = 0;
    FOR(i,1,n+1,1)FOR(j,1,m+1,1)DP[i+j][arr[i][j]]++;
    FOR(i,2,n+m+1,1){
        int aux = n + m - i;
        if(i <= n + m - i + 2) goto brinca;
        res = res + min(DP[i][0] + DP[aux + 2][0] , DP[i][1] + DP[aux + 2][1]);
        brinca :;
    }
    cout<<res<<endl;
}

return 0;
}