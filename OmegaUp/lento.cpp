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
ll n;
cin>>n; 
ll arr[n];
ll sum = 0;
ll menorImp = 1<<31-1;
FOR(i,0,n,1){
    cin>>arr[i];
    sum+=arr[i];
    if(arr[i]<menorImp && arr[i]%2==1) menorImp = arr[i];
}

if(sum%2==1){cout<<sum;}
if(sum%2==0){
    sum-=menorImp; 
if(sum<=0){cout<<0;return 0;}
cout<<sum;
}
}