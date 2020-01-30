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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;

ll gcd(ll a,ll b){
   return b==0 ? a : gcd(b,a%b);
}

bool isPrime(int n) {
if (n <= 1) return false;
if (n <= 3) return true;
if (n % 2 == 0 || n % 3 == 0) return false;
for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false;
return true;
}

int main(){
sync;

int n; cin>>n;
while(n--){
    int k; cin>>k;
   
    int arr[k];
    unsigned long long prod = 1;
    int minP;
    FOR(i,0,k,1){
        
        ull x; cin>>x;

        if(i==0)minP = x;
        if(isPrime(x)){
            minP = min(minP,x);
        }
    
    }
//(x-y)/p = -floor(y/p) + floor(x/p)

    cout<<minP<<endl;

}

return 0;
}