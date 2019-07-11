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
int n; cin>>n; 
vi arr; int aux;
int peligro = 0, peligro2 = 0;
int sum = 0;
vi pares;
vi pares2;
FOR(i,0,n*2,1)cin>>aux,arr.pb(aux);
sort(arr.begin(), arr.end());


//pares
FOR(i,0,n*2,2)peligro+=abs(arr[i]-arr[i+1]),pares.pb(abs(arr[i]-arr[i+1]));
FOR(i,1,n*2-1,2)peligro2+=abs(arr[i]-arr[i+1]),pares2.pb(abs(arr[i]-arr[i+1]));

sort(pares.begin(), pares.end());

peligro-=pares[n-1];
//FOR(i,0,n-1,1)peligro2+=pares[i];

cout<<min(peligro2,peligro)<<endl;



return 0;
}
