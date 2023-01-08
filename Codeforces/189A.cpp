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
#define max(a,b) (a>b?a:b)
using namespace std;

int main(){
sync;

int n, a,b,c; cin>>n>>a>>b>>c;
ll maxim = 1;
FOR(i,0,n+1,1){
    FOR(j,0,n - i + 1,1){
        ll calc = n - a * i - b * j;
        if(calc >= 0){
            
            ll k = 0;
            if(calc % c == 0){
                k = calc / c;
            } 
            if(a * i + b * j + c * k == n){
                //if(i == 1)
                //cout<<"i = "<<i<<", j = "<<j<<", k = "<<k<<endl;
                maxim = max(maxim, i + j + k);
            }
        }
    }
}
cout<<maxim<<endl;

return 0;
}