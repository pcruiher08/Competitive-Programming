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
#define mod 998244353 
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

long long inve(long long a){
   long long b = mod-2, ans = 1;
   while (b) {
       if (b&1) {
           ans = (ans * a) % mod;
       }
       a = (a * a) % mod;
       b >>= 1;
   }
   return ans;
}

int main(){
sync;

for(int i=1; i<14; i++){
    for(int j = 1; j<14; j++){
        if((i*inve(j))%mod == 124780545){
            cout<<i<<" "<<j<<endl;
            cout<<"eureka"<<endl;
        }
    }
}



return 0;
}