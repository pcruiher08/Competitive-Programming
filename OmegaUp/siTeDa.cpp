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
int a,b;
cin>>a>>b;
int auxA=a, auxB=b;
int cuenta = 0;
vi nums;
nums.pb(a);
nums.pb(b);
nums.pb((a+b)%10);

while(!(nums[nums.size()-1]==b&&nums[nums.size()-2]==a)){
    cuenta++;
    nums.pb((nums[cuenta]+nums[cuenta+1])%10);
}

FOR(i,0,nums.size(),1)cout<<nums[i]<<" ";
cout<<endl;
cout<<cuenta+1;


return 0;
}