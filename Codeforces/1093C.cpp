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

ll res[200010];

int main(){
sync;
ll n;
cin>>n;
ll b[n/2+1];
FOR(i,1,n/2+1,1)cin>>b[i];



FOR(i,1,n/2+1,1){
    if(i==1){
        res[1]=0;
        res[n] = b[1];
    }else{
        if(res[i-1]>b[i]-res[n-i+2]){
            res[i] = res[i-1];
        }else{
            res[i] = b[i]-res[n-i+2];
        }
        res[n-i+1] = b[i]-res[i];
    }
}

FOR(i,1,n+1,1) cout<<res[i]<<" ";
/*
4
1000000000000000001
1000000000000000000
*/

return 0;
}