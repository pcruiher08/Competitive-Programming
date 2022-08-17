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

ll fastPow(ll a,ll b){
   ll ret = 1;
   while(b>0){
       if(b&1) ret = (ret*a%mod);
       a=(a*a%mod);
       b>>=1;
   }
   return ret;
}
 

ull fib(ull a, ull b, ull n){
    return round( (((2*a + b*(1+sqrt(5))) * fastPow(1+sqrt(5),n-1)) - ((2*a+b*(1-sqrt(5))) * fastPow(1-sqrt(5),n-1) )) / (sqrt(5) * (1<<n)) );
}


ull fib(ull a, ull b, ull n){
   if (n == 0)
       return 0;
   if (n == 1)
       return a;
   if (n == 2)
       return b;
   ull k = (n & 1)? (n+1)/2 : n/2;
   return (n & 1)? (fib(a,b,k)%mod*fib(a,b,k)%mod + fib(a,b,k-1)%mod*fib(a,b,k-1)%mod)%mod : (2*fib(a,b,k-1)%mod + fib(a,b,k)%mod)%mod*fib(a,b,k)%mod;
}

int main(){
sync;
int n; cin>>n;

while(n--){
    ull a,b,c;
    cin>>a>>b>>c;
    FOR(i,0,10,1)
    cout<<fib(a,b,i)<<", ";
    cout<<endl;
}
return 0;
}