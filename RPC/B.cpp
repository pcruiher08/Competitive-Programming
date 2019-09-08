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
#define FOR(m,s,n,u) for(ll m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(ll m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(ull m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define MOD(x) (x%mod+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

ll gcd(ll a,ll b){
    return b==0 ? a : gcd(b,a%b);
}

ll fastPow(ll base , ll k){
    ll res=1ll;
    while(k){
        if(k&1){
            res=MOD(res*base%mod);
        }
        base=MOD(base*base%mod);
        k/=2;
    }
    return MOD(res);
}

ull dp1[1000000], dp2[1000000];
int main(){
sync;
ull n,m,c,multiplicador = 1, cuenta = 0, respuesta = 0; 
dp2[0]=1;
cin>>n>>m>>c;
FOR(i,1,n*n+1,1)multiplicador=MOD(multiplicador*c%mod);//c^(n^2)
FOR(i,1,m+1,1)dp2[i]=MOD(dp2[i-1]*multiplicador);
FOR(i,0,m,1)dp1[i]=gcd(i,m);
FOR(i,0,m,1)cuenta+=MOD(dp2[dp1[i]]);
cout<<MOD(cuenta*fastPow(m,mod-2)%mod)<<endl;
return 0;
}