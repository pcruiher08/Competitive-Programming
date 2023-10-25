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

bool cut(int a, int b, int c) {
    int t[] = {a, b, c};
    sort(t, t + 3);

    if(t[0] == t[1] && t[0] == t[2]) return true;
    if(t[0]*2 == t[1] && t[0] == t[2]) return true;
    if(t[0]*3 == t[1] && t[0] == t[2]) return true;
    if(t[0] == t[1] && t[0]*2 == t[2]) return true;
    if(t[0] == t[1] && t[0]*3 == t[2]) return true;
    if(t[0]*2 == t[1] && t[0]*2 == t[2]) return true;
    if(t[0]*3 == t[1] && t[0]*2 == t[2]) return true;
    if(t[0]*2 == t[1] && t[0]*3 == t[2]) return true;
    if(t[0]*4 == t[1] && t[0] == t[2]) return true;
    if(t[0] == t[1] && t[0]*4 == t[2]) return true;



    return false;

}

int main(){
sync;



int t; cin>>t;
while(t--){
    int a, b, c; cin>>a>>b>>c;
    bool flag = false;
    int minLen = min(a, min(b, c));

    flag = cut(a,b,c);

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

return 0;
}