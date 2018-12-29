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
#define FOR(m,s,n,u) for(ull m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

ll res;
int main(){
sync;
ll n; cin>>n;

n-=(n%2!=0);

ll potDos = 1;
ll sum = 0;

while(potDos*2<=n)sum++, potDos*=2;
ll y=1, x=2, base = 0, aumento = 1;

FOR(i,1,sum+1,1){
    res += (((n/2)-base)/x)*y + min((((n/2)-base)%x),y);
    base += aumento;
    aumento*=2;
    x*=2;
    y*=2;
}

cout<<res<<endl;
}