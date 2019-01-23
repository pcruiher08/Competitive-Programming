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
int n; cin>>n;
vi nums;
int x;
FOR(i,0,n,1)cin>>x,nums.pb(x);
sort(nums.begin(),nums.end());
int max = nums[n-1];
int maxDos = nums[n-2];
vi factorsOfMax;

for (int i = 1; i < (int) sqrt(max) + 1; i++) { 
    if (max % i == 0&&i*i!=max){
        factorsOfMax.pb(i);
        factorsOfMax.pb(max/i);
    }
    if (max % i == 0&&i*i==max){
        factorsOfMax.pb(i);
    }
}
sort(factorsOfMax.begin(),factorsOfMax.end());

set<int> solos;

FOR(i,0,(int)factorsOfMax.size(),1)solos.insert(factorsOfMax[i]);

FOR(i,0,n,1){
    solos.insert(nums[i]);
    if(solos.size()==factorsOfMax.size()){
        nums.erase(std::remove(nums.begin(), nums.end(), factorsOfMax[i]), nums.end());
    }
}

if(nums.size()==0){
    cout<<max<<" "<<maxDos<<endl;
}else{
    cout<<max<<" "<<nums[nums.size()-1]<<endl;
}

return 0;
}