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

ll extendedGCD(ll a,ll b,int &x, int &y){
   if(a==0){
   x=0; y=1;
   return b;
}
   int x1,y1;
   int d = extendedGCD(b%a,a,x1,y1);
   x = y1-(b/a)*x1;
   y=x1;
   return d;
}


int main(){
sync;
int a,b;
while(cin>>a>>b){
    int x,y; 
    int g = extendedGCD(a,b,x,y);
    if(a==b){
        x=0;
        y=1;
    }
    cout<<x<<" "<<y<<" "<<g<<endl;
}

return 0;
}