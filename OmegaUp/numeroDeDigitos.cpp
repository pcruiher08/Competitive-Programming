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
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
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
    int n;
    cin>>n;
    int d = 1;
    if(n>9) d = 2;
    if(n>99) d = 3; 
    if(n>999) d = 4; 
    if(n>9999) d = 5;
    if(n>99999) d = 6; 
    if(n>999999) d = 7;
    if(n>9999999) d = 8; 
    if(n>99999999) d = 9; 
    int res = (n+1)*d - (fastPow(10,d)-1)/9;
    cout<<res;
}