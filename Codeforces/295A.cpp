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

struct op{
    ll l,r,d;
};
void update(ll a[], ll acc[], vector<op> operations, ll x, ll y, ll n){
    FOR(j,x-1,y,1){
        FOR(k,0,n,1){
            if(a[k] >= operations[j].l && a[k] <= operations[j].r){
                acc[k]+=operations[j].d;
            }
        }
    }

}
int main(){

sync;

ll n,m,k;
cin>>n>>m>>k;
ll a[n+5];
ll acc[m+5];
ll b[n+5];

FOR(i,1,n+1,1){cin>>a[i]; }
FOR(i,0,n+5,1){b[i]=0;}
FOR(i,0,m+5,1){acc[i]=0;}


vector<op> operations;

op vacia; operations.pb(vacia);
FOR(i,0,m,1){
    op oper;
    cin >> oper.l >> oper.r >> oper.d;
    operations.pb(oper);
}

FOR(i,1,k+1,1){
    int x, y; cin>>x>>y;
    acc[x]++;
    if( (y+1) > (m + 5)){
        cout<<"me estoy pasando"<<endl;
    }
    acc[y+1]--;
    //update(a,acc,operations,x,y,n);
}
FOR(i,2,m+1,1){
    acc[i] += acc[i-1];
}
FOR(i,1,m+1,1){
    b[operations[i].l] += operations[i].d * acc[i];
    b[operations[i].r + 1] -= operations[i].d * acc[i];

}
ll sum = 0;
FOR(i,1,n+1,1){
    sum += b[i];
    cout<<a[i]+sum<<(i!=n?" ":"\n");
}

return 0;
}