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

ll fastPow(ll a,ll b){
    ll ret = 1;
    while(b>0){
        if(b&1) ret = (ret*a);
        a=(a*a);
        b>>=1;
    }
    return ret;
}

int main(){
sync;
int n; cin>>n; 
while(n--){
    int type; cin>>type; 
    switch (type)
    {
        case 1:
            int a; cin>>a; 
            cout<<(a<0?a*-1:a)<<endl;
            break;
        case 2: 
            int b,c; cin>>b>>c; 
            cout<<max(b,c)<<endl;
            break;
        case 3:
            int d,e; cin>>d>>e; 
            cout<<min(d,e)<<endl;
            break;
        case 4:
            int f; cin>>f;
            cout<<setprecision(2)<<fixed<<sqrt(f)<<endl;
            break;
        case 5: 
            int g, h; cin>>g>>h; 
            cout<<fastPow(g,h)<<endl;
            break;
    }
}
return 0;
}