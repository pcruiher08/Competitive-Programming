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


ll rango(vector<int> arr, int a, int b){
    return arr[b] - arr[a - 1];
}


const int upperBound = 2 * 100000 + 5;
int x[upperBound];

int main(){
sync;
int t; cin>>t;
while(t--){
    int n,k; cin>>n>>k;
    int limite = n;
    FOR(i,1,n+1,1){
        int lec; cin>>lec;
        x[i]=lec;
    }

    FOR(i,0,n,1){
        int lec; cin>>lec;
    }
    sort(x+1,x+n+1);
    int segunda = 0;
    int res = 0;
    FOR(i,1,n+1,1){
        //upper y lower son punteros
        int revisa = upper_bound(x + i, x + n + 1, x[i] + k) - x;
        res = max( res , segunda + revisa - i);
        revisa = lower_bound(x + 1, x + i, x[i] - k) - x;
        segunda = max(segunda, i - revisa + 1);
    }
    cout<<res<<endl;

    /*
1
7 1
1 5 2 3 1 5 4
1 3 6 7 2 5 4
    */

}
return 0;
}