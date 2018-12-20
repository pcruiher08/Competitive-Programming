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

const int MAX = 1000001; 
ull f[MAX] = {0};

ull fib(ull n){ 
    if (n == 0)
        return 0; 
    if (n == 1 || n == 2) 
        return (f[n] = 1); 
    if (f[n])
        return f[n];
    ull k = (n & 1)? (n+1)/2 : n/2;
    f[n] = (n & 1)? (fib(k)%mod*fib(k)%mod + fib(k-1)%mod*fib(k-1)%mod)%mod : (2*fib(k-1)%mod + fib(k)%mod)%mod*fib(k)%mod;
    return f[n]%mod;
}

int main(){
    sync;
    int a,b;
    cin>>a>>b;
    int wheresA, wheresB;
    FOR(i,0,1000001,1){
        cout<<f[i]<<" ";
        if(fib(i-1)==a){
            wheresA  = i;
        }
        if(fib(i-1)==b){
            wheresB = i;
            break;
        }
    }
    cout<<wheresB-wheresA<<endl;
}