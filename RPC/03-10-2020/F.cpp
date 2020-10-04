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
ll dp[302][302][302];

ll proc(int x, int y, int z, int lenA, int lenB, int lenC, string a, string b, string c, string busca){
    
    ll calc = 0;
    ll sum = x+y+z;
    if(lenA == x && lenB == y && lenC == z){
        return 1;
    }

    if(dp[x][y][z] != -1){
        //ya pase por aqui
        return dp[x][y][z];
    }

    if(x < lenA && a[x] == busca[sum]){
        calc = MOD(calc + proc(x+1,y,z,lenA,lenB,lenC,a,b,c,busca));
    }

    if(y < lenB && b[y] == busca[sum]){
        calc = MOD(calc + proc(x,y+1,z,lenA,lenB,lenC,a,b,c,busca));
    }

    if(z < lenC && c[z] == busca[sum]){
        calc = MOD(calc + proc(x,y,z+1,lenA,lenB,lenC,a,b,c,busca));
    }


    dp[x][y][z] = calc;
    return calc;
}


int main(){
sync;
string a, b, c, busca;
cin>>a>>b>>c>>busca;
FOR(i,0,302,1)FOR(j,0,302,1)FOR(k,0,302,1)dp[i][j][k] = -1;

int lenA = a.length();
int lenB = b.length();
int lenC = c.length();


ll ans = 0;

ans = proc(0,0,0,lenA,lenB,lenC,a,b,c,busca);

cout<<ans<<endl;

return 0;
}