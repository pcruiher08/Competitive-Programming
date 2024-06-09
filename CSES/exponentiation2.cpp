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
#define mod1 1000000007
#define mod2 1000000006
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD1(x) ((x%mod1)+mod1)%mod1
#define MOD2(x) ((x%mod2)+mod2)%mod2
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

ull fastPow2(ull a,ull b){
   ull ret = 1;
   while(b>0){
       if(b&1) ret = (MOD2(ret*a));
       a=MOD2(a*a);
       b>>=1;
   }
   return MOD2(ret);
}

ull fastPow1(ull a,ull b){
   ull ret = 1;
   while(b>0){
       if(b&1) ret = (MOD1(ret*a));
       a=MOD1(a*a);
       b>>=1;
   }
   return MOD1(ret);
}


int main(){
sync;

ull t; cin>>t;
while(t--){
    ull a, b, c; cin>>a>>b>>c;
    cout<<MOD1(fastPow1(a,MOD2(fastPow2(b,c))))<<endl;
}

return 0;
}