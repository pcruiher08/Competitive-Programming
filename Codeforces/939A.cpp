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
int amor[3][n];
FOR(i,0,n,1)cin>>amor[0][i];
FOR(i,0,n,1)amor[1][i] = amor[0][amor[0][i]-1];
FOR(i,0,n,1) amor[2][i] = amor[1][amor[1][i]-1];
FOR(i,0,n,1)if(amor[0][i] == amor[2][i]){cout<<"YES"<<endl; return 0;}
cout<<"NO"<<endl;
return 0;
}