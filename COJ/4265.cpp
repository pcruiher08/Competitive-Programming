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
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

void fastscan(int &x){
    char ch; bool f= 0; int a=0; 
    while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));
    if(ch!='-')a*=10,a+=ch-'0';else f=1;
    while(((ch=getchar())>='0')&&(ch<='9'))a*=10, a+=ch-'0';
    if(f)a=-a;x=a;
}

int main(){
sync;
int n; cin>>n;

while(n--){
    int a,b;
    fastscan(a);
    fastscan(b);
    cout<<1 + min(a,b) + (int)( (max(a,b)-min(a,b)) * (a>b?0.301029995663981195:0.698970004336) )<<'\n';
}

return 0;
}