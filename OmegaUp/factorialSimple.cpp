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
unsigned long long fact[100001];
unsigned long long actual = 1;
unsigned long long fac(long long n){
    fact[0]=1;
    fact[1]=1;
    if(n>actual){
    for(unsigned long long i=actual; i<=n; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    actual = n;
    }
    return fact[n];
}
int main(){
sync;
int m; cin>>m;
cout<<fac(m)<<endl;
return 0;
}