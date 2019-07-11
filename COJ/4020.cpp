#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
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
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

ll fastPow(ll a,ll b,ll m){
    ll ret = 1;
    while(b>0){
        if(b&1) ret = (ret*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ret;
}
ll arr[1000001];
int main(){
sync;

ll n;
ll k;
cin>>n;

memset(arr,0,sizeof(arr));
while(n--){
    cin>>k;
    if(!arr[k]){
        arr[k] = (fastPow(k,k+1,mod) - k + 1);
    }
    cout<<arr[k]<<endl;
}

return 0;
}