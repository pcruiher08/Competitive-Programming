#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
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
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
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

bool isSquare(ull x){
ull s = sqrt(x);
return (s*s == x);
}

bool isFib(ull n){
return isSquare(5*n*n+4)||isSquare(5*n*n-4);
}



int main(){
sync;

int n; cin>>n;
cout<<n<<" "<<0<<" "<<0;
return 0;
}