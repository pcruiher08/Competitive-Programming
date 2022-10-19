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
#define FOR(m,s,n,u) for(long long m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
//#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
//#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;
 
long long MOD(long long x, long long m){
    return ((x%m)+m)%m;
}

int main(){
sync;
long long n,m; cin>>n>>m;
long long last = 1;
long long accum = 0;
long long actual  = 1;
FOR(i,0,m,1){
    long long x; cin>>x;

    accum += MOD(x - actual, n);

    //cout<<actual - x << " ... " << MOD(x - actual, n )<<endl;

    actual = x;

}
cout<<accum<<endl;
return 0;
}