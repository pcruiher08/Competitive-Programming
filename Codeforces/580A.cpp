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
int n; cin>>n; 
int arr[n];
int dp[n];
FOR(i,0,n,1)cin>>arr[i], dp[i] = 0;

FOR(i,0,n,1)dp[i] = 0; 
dp[0] = 1;
int compara = arr[0];

FOR(i,1,n,1){

    if(arr[i] < compara){
        dp[i] = 1;
    }

    compara = arr[i];
}
int maximo = INT_MIN;
int cuenta = 1; 
FOR(i,0,n,1){
    if(dp[i]){
        maximo = max(cuenta,maximo);
        cuenta = 1;
    }else{
        cuenta++;
    }
    maximo = max(cuenta, maximo);
}
cout<<maximo<<endl;;

return 0;
}