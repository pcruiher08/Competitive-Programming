#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define min(x,y) x<y?x:y
#define pb push_back
#define mod 1000000009
#define MOD(x) ((x%mod)+mod)%mod
using namespace std;



long long fastPow(long long a, long long b){
    long long ret = 1;
    while(b>0){
        if(b&1LL) static_cast<void>(ret *= a), ret%=mod;
        b>>=1;
        a*=a;
        a%=mod;
    }
    return ret;
}


int main() {
    int n = 0,a = 0,b = 0,k = 0;//2 2 3 4
    cin>>n>>a>>b>>k;
    ll rep = fastPow(fastPow(a, mod-2)*b%mod,k);
    if(rep==1) rep = (n+1)/k;
    else rep = (fastPow(rep,(n+1)/k)-1)*(fastPow(rep-1,mod-2)) % mod;
    char signs[100000];
    cin>>signs;
    /*vector <char> signs;
    char sign;
    while(k--)static_cast<void>(cin>>sign),signs.pb(sign);
    while(signs.size()<=n) signs.pb('-');*/
    ll res=0;
    FOR(i,0,k,1)res+=fastPow(a, n-i)*fastPow(b, i)%mod*rep%mod*(signs[i]=='+'?1:-1);
    cout<<((res%mod)+mod)%mod;

}