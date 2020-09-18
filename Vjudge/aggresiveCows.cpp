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
ll n,vacas; cin>>n>>vacas;
ll arr[n+10];
FOR(i,0,n,1)cin>>arr[i];sort(arr,arr+n);

ll derecha=arr[n-1]-arr[0];
ll izquierda=0;
ll centro;
int res=-1;

while(izquierda<derecha){
    ll cuantasVan=1, ultimo=0;
    centro=(izquierda+derecha)/2;
    FOR(i,0,n,1){
        if(centro<=arr[i]-arr[ultimo]){
            cuantasVan++;
            if(cuantasVan==vacas)
                break;
            ultimo=i;
        }
    }
    if(cuantasVan<vacas){
        derecha=centro;
    }else{
        izquierda=centro+1;
    }
    if(cuantasVan==vacas&&centro>res){
        res=centro;
    }
}
cout<<res<<endl;
}
return 0;
}


