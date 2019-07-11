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

ll gcd(ll a, ll b){
    if(b) return gcd(b, a%b);
    return a;
}

int main() {
    ll n,m,k,g;
    sync;
    cin>>n>>m>>k;
    g=gcd(k,n*2);
    if(n*m*2%k!=0){
        cout<<"NO";
        return 0;
    }
    else if(g==1)
        m=m*2/k;
    else
    {
        n=n*2/g;
        m=m*g/k;
    }
    cout<<"YES"<<endl;
    cout<<"0 0\n"<<n<<" 0\n0 "<<m<<endl;
}