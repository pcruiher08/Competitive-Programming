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
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int main(){
sync;

ull n,m; cin>>n>>m; 
ull k; cin>>k; 
ull x,y; cin>>x>>y;


ull costoHorizontal = (m-1) * x + y; 
ull costoVertical = (n-1) * y + x; 
if(costoHorizontal * n - y <= k || costoVertical * m - y <= k){
    cout<<n*m<<endl;
}else if(x<y){
    ull filas = k / costoHorizontal;
    k-= filas * costoHorizontal;
    cout<<m*filas + min(k/x, m-1) + 1 <<endl;
}else{
    ull columnas = k / costoVertical; 
    k-= columnas * costoVertical; 
    cout<<n * columnas + min(k / y, n-1) +1 <<endl;
}




return 0;
}