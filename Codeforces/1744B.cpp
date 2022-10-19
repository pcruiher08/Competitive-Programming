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
    ll n, q; cin>>n>>q;

    ll pares = 0;
    ll impares = 0;
    ll suma = 0;
    FOR(i,0,n,1){
        ll x; cin>>x;
        if(x&1){
            impares++;
        }else{
            pares++;
        }
        suma+=x;
    }
    ll sumaDeParidades = 0;
    FOR(i,0,q,1){
        ll type = 0, value = 0; 
        cin>>type>>value;
        if(type){
            //impares
            sumaDeParidades += (value * impares);
            if(value&1){
                impares = 0;
                pares = n;
            }
        }else{
            //pares
            sumaDeParidades += (value * pares);
            if(value&1){
                pares = 0;
                impares = n;
            }
        }
    cout<<suma+sumaDeParidades<<endl;


    }   
    //cout<<suma+sumaDeParidades<<endl;
}

return 0;
}