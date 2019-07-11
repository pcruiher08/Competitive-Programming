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

void rArr(int a[], int s, int e) { 
    while (s < e) { 
        int t = a[s];  
        a[s] = a[e]; 
        a[e] = t; 
        s++; 
        e--; 
    }  
}  

int main(){
sync;
int n,m,k; cin>>n>>m>>k;
int arr[n];
bool flag = false;
FOR(i,0,n,1)cin>>arr[i];
int subs = 0;
rArr(arr,0,n);
FOR(i,0,n,1){
    if(subs - arr[i] < 0){
        if(!m){cout<<i<<endl; flag = true; break;}
        else{m--; subs = k-arr[i];}
    }else{
        subs -= arr[i];
    }
}
if(!flag)
cout<<n<<endl;

return 0;
}
