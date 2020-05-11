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

int main(){
sync;
ll t; cin>>t; 
while(t--){
    ll n,d; cin>>n>>d; 

    ll arr[n];
    FOR(i,0,n,1)cin>>arr[i];
    map<ll,ll> mv[d];
    //map<ll,ll> mv[d];

    bool mioncas[n];
    memset(mioncas,false,sizeof(mioncas));

    FOR(i,0,n,1){
        ll sumador = 0;
        FOR(j,arr[i],d,arr[i]){
            mv[j].insert({0,arr[i]});
        }
    }


    FOR(i,0,n,1){
        pair<ll,ll> p;
        p = mp(0,arr[n-i-1]);
        if(mv[i].find(p) != mv[i].end()){
            cout<<i<<endl;
            break;
        }
    }



}
return 0;
}