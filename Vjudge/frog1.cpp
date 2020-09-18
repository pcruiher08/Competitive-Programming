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
int arr[n+1];
FOR(i,1,n+1,1)cin>>arr[i];

int DP[n+1];
DP[2] = max(arr[1],arr[2]) - min(arr[1],arr[2]);

FOR(i,3,n+1,1){
    int dif1 = abs(arr[i]-arr[i-1]);
    int dif2 = abs(arr[i]-arr[i-2]);
    DP[i] = min(DP[i-1] + dif1 , DP[i-2] + dif2);
}
cout<<DP[n];


return 0;
}