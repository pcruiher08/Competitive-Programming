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
#define mod 10000
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;
int arr[40000000];

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
int suma,start, end, aux = 1;
int n,m; cin>>suma>>n>>m;

FOR(i,0,n,1){
    cin>>start>>end;
    for(int j = start, aux = 1; j<=end; j++, aux++)arr[j] += aux,arr[j] %= mod;
}

FOR(i,0,m,1){
    suma = 0; cin>>start>>end;
    FOR(j,start,end+1,1)suma += arr[j],suma %= mod;
    cout<<suma<<endl;
}


}