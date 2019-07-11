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
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>

using namespace std;

long long fastPow(ll a, ll b){
    long long ret = 1;
    while(b>0){
        if(b&1){
            ret *= a;
            ret%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ret;
}

int main(){
    ll n;
    string s;
    cin>>n;
    //int res[n];
    cin>>s;
    //char p;
    ll countA = 0, countC = 0, countG = 0, countT = 0;
    for(int i=0; i<n;i++){
        //cin>>p;
        //res[s[i]-'A'];
        if(s[i]=='A') countA++;
        if(s[i]=='G') countG++;
        if(s[i]=='T') countT++;
        if(s[i]=='C') countC++;
    }
    ll maximo = countA;
    if(countC>maximo) maximo=countC;
    if(countG>maximo) maximo=countG;
    if(countT>maximo) maximo=countT;
     
    //maximo = max(countA,max(countC,max(countG,countT)));
    ll cuenta = 0;
    if(countA==maximo) cuenta++;
    if(countC==maximo) cuenta++;
    if(countG==maximo) cuenta++;
    if(countT==maximo) cuenta++;
    
    //cout<<pow(cuenta, n);
    cout<<fastPow(cuenta,n);
}