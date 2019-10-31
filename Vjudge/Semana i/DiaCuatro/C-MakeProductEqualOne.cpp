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
ll n; cin>>n; 
ll arr[n];
ll aux = 0;
ll monedas = 0, cambiarlos = 0; 
FOR(i,0,n,1)cin>>arr[i];

FOR(i,0,n,1){

    if(arr[i]-1==-1){
        cambiarlos = 1; 
        monedas++;
    }else{
        if(arr[i]*-1>0){
            aux++;
        }
    }

    if(arr[i]>0 ||arr[i]<0){
        if(arr[i]<0){
            monedas = monedas + (arr[i])*-1 - 1;
        }else{
            monedas = monedas + arr[i] - 1;
        }
    }
}

if(cambiarlos==0){
    if(aux%2!=0){
        monedas++;
        monedas++;
    }
}
cout<<monedas<<endl;
return 0;
}