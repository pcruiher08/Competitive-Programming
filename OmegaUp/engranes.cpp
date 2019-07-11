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

bool processed[1000002], different[1000002];
ll m,n, howMany, colors[1000002];


ll gcd(ll a,ll b){
    return b==0 ? a : gcd(b,a%b);
}

bool isOk(ll k){
    int engranito = k%n;
    int color = colors[engranito];
    int hop = m%n;
    bool res = true;

    if(processed[engranito]) return different[engranito];

    FOR(i,1,howMany, 1){
        engranito = (engranito + hop) %n;
        if(colors[engranito]!=color){ res = false; break;}
    }
    engranito = k%n;
    different[engranito] = res; 
    processed[engranito] = true;
    FOR(i,1,howMany,1)engranito = (engranito+hop)%n, different[engranito]=res, processed[engranito]=true;
    return res;
}

int main(){
sync;
ll x, l, k;
cin>>n>>m>>k;
FOR(i,0,n,1)cin>>colors[i];
cin>>l;
howMany = n/gcd(n,m);

FOR(i,0,l,1){cin>>x; cout<<(isOk(x)?'1':'0');}

return 0;
}