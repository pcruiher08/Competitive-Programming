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

int main(){
sync;
string a; cin>>a; 

bool isFirstLower = false; 
bool areRestUpper = true;
if(a[0]<='z'&&a[0]>='z') isFirstLower = true; 
FOR(i,1,a.size(),1)if(a[i]>'Z'||a[i]<'A') areRestUpper = false;

bool areAllUpper = true;
FOR(i,0,a.size(),1)if(a[i]>'Z'||a[i]<'A') areAllUpper = false;

if((isFirstLower &&  areRestUpper) || areAllUpper){
    a[0]=toupper(a[0]);
    FOR(i,1,a.size(),1)a[i]=tolower(a[i]);
}
cout<<a<<endl;

return 0;
}