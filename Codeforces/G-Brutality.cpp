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

bool func(char a, char b){
    return a>b;
}

int main(){
sync;
int n,k; cin>>n>>k; 
int aux; 
int arr[n];
int res = 0;
FOR(i,0,n,1)cin>>arr[i];
string combo; 
cin>>combo;
int cuenta1, cuentaRangoDeLetras; 
cuenta1 = 0; cuentaRangoDeLetras = 0; 
while(cuenta1<n){
    cuentaRangoDeLetras = 0;
    while(cuentaRangoDeLetras<n && combo[cuenta1]==combo[cuentaRangoDeLetras+cuenta1])cuentaRangoDeLetras++;
    priority_queue<int, vector<int>, less<int> > pq;
    FOR(i,cuenta1,cuenta1+cuentaRangoDeLetras,1)pq.push(arr[i]);
    int c = 0;
    while(!pq.empty() && c < k){
        res+=pq.top(), pq.pop();
        c++;
    }
    cuenta1+=cuentaRangoDeLetras;
    
}
cout<<res<<endl;

return 0;
}