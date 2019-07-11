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
long long howManyNeg = 0;
long long arr[n];
FOR(i,0,n,1){
    cin>>arr[i]; 
    if(arr[i]<0)howManyNeg++;
}

//FOR(i,0,n,1)cout<<"i"<<i<<": "<<arr[i]<<endl;
sort(arr,arr+n);

long long res;
if(howManyNeg<2){
    res=arr[n-1]*arr[n-2];
}else{

    res = max(arr[n-2]*arr[n-1],arr[0]*arr[1]);
}
//cout<<howManyNeg<<endl;
cout<<res<<endl;

return 0;
}