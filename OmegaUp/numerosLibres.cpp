#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
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
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

ull gcd(ull a, ull b){
    return b==0 ? a : gcd(b,a%b);
}

string res(ll a, ll b){
    if(gcd(a,b)!=1)
        return "NO";
    return "SI";
}

int main(){
sync;
ull n, a, b;
cin>>n;

while(n--){
    cin>>a>>b;
    cout<<res(a,b)<<endl;
}
}