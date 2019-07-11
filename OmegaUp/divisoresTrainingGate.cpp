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
#define FOR(m,s,n,u) for(ull m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;


void factPrim(ull n){
    vi primfact;
    FOR(i,1,sqrt(n),1){
        if(n%i==0&&i*i!=n){primfact.pb(i); primfact.pb(n/i);}
        if(n%i==0&&i*i==n)primfact.pb(i);
    }
    
    sort(primfact.begin(),primfact.end());
    cout<<primfact.size()<<endl;
    FOR(i,0,primfact.size(),1)if(i<primfact.size()-1)cout<<primfact[i]<<" ";else cout<<primfact[i]<<endl;
}

int main(){
sync;
ull n; 
while(1){
cin>>n;
if(n==0)break;
factPrim(n);
}

return 0;
}
/*
10
12
0
*/