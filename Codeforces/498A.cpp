#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=2; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000009
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>

using namespace std;

#include <iostream>

int main(){
    sync;
    ll x1,x2,y1,y2,n;
    ll a,b,c;
    
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>n;
    ll uno[n];
    ll dos[n];
    for(int i=0; i<n; i++){
        cin>>a>>b>>c;
        uno[i] = (a*x1+b*y1+c);
        dos[i] = (a*x2+b*y2+c);
    }
    ll cuenta = 0;
    for(int i=0; i<n; i++){
        if((uno[i]>0)!=(dos[i]>0)){
            cuenta++;
        }
    }
    cout<<cuenta;
}