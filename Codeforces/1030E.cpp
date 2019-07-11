#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iomanip>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int n;
vector<int> b, s;

int bits(ll x) {
    int ret=0;
    while(x!=0){
        ret+=x&1;
        x>>=1;
    }
    return ret;
}

int main() {
    sync;
    cin>>n;
    b.resize(n+1,0);
    s.resize(n+1,0);
    for (int i=1; i<=n; ++i){
        ll x;
        cin>>x;
        b[i]=bits(x);
        s[i]=b[i]+s[i-1];
    }
    ll ans=0;
    vector<int> cuenta(2, 0);
    FOR(i,1,n+1,1){
        ans+=cuenta[s[i]&1];
        for (int j=i-2, m=max(b[i], b[i-1]); j>=0&&i-j<=60; --j){
            if ((s[j]&1)==(s[i]&1)&&2*m>s[i]-s[j]){
                --ans;
            }
            m=max(m,b[j]);
        }
        ++cuenta[s[i-1]&1];
    }
    cout<<ans<<endl;
}