#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000009
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int main(){
    sync;
    ll n; cin>>n;
    ll sum=0,res[n],arr[n];
    FOR(i,0,n,1)cin>>arr[i];
    FOR(i,0,n-1,1)sum+=(abs(arr[i]-arr[i+1])*(i%2==0?1:-1)),res[i]=sum;
    sort(res,res+n-1);
    cout<<(res[0]>=0?res[n-2]:res[n-2]-res[0]);
}