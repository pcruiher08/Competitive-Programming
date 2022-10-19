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

ll lcm(ll a,ll b){
   return (a*b)/gcd(a,b);
}

int rightbit(int n){


    int p = 1;
 
    while (n > 0) {
        if (n & 1) {
            return p;
        }
 
        p++;
        n = n >> 1;
    }
 
}

ll fastPow(ll a,ll b){
   ll ret = 1;
   while(b>0){
       if(b&1) ret = (ret*a%mod);
       a=(a*a%mod);
       b>>=1;
   }
   return ret;
}

ll V2(ll n){
   ll p = (ll)log2(n);
   return (ll)fastPow(2, p);
}

int main(){
sync;
ll t; cin>>t; 
while(t--){
    ll n; cin>>n;
    ll sum = 0;
    ll arr[n]; 
    FOR(i,0,n,1){
        ll x; cin>>x; 
        int k = rightbit(x) - 1; 
        //cout<<"k "<<k<<endl;
        arr[i] = k; 
        sum += k;
    };

    //cout<<"prod "<<prod<<endl;
    vector<int> sorteo;
    FOR(i,1,n+1,1){
        sorteo.push_back(rightbit(i) - 1);
    }
    sort(sorteo.begin(), sorteo.end());
    reverse(sorteo.begin(), sorteo.end());
    //FOR(i,0,n,1)cout<<sorteo[i]<<" ";cout<<endl;
    ll cuenta = 0;
    ll multi = rightbit(n);
    //cout<<"2^n "<<(1<<n)<<endl;
        //cout<<"prod "<<prod<<endl;
    int index = 0;
    bool flag = false;
    //cout<<"res ";
    FOR(i,0,n,1){
        if(sum >= n){
            cout<<cuenta<<endl;
            flag = true;
            break;
        }
        sum += sorteo[i];
        cuenta++;
    }
    if(!flag)
    cout<<-1<<endl;



    

}

return 0;
}