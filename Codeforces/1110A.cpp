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

int val(char c){ 
    if (c >= '0' && c <= '9') 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 

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
int base, len; 
cin>>base>>len;

//string read = "";
vi read;
int x;

FOR(i,0,len,1)cin>>x,read.pb(x);

long odd = 0;

if(base&1){
  FOR(i,0,len,1){/*cout<<"power: "<<len-i-1<<" "; cout<<"num: "<<read[i]<<" ";cout<<fastPow(base,len-i-1)*read[i]<<endl; */if(fastPow(base,len-i-1)*read[i] & 1)odd++;}
  //cout<<"oddcount: "<<odd<<endl;
  cout<<((odd & 1)?"odd":"even")<<endl;
}else{
  cout<<((read[len-1]&1)?"odd":"even")<<endl;
}

return 0;
}