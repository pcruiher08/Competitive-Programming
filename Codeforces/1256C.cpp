#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
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
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int main(){
sync;
int n,m,d,longitud = 0;
cin>>n>>m>>d;

int arr[n+10];
int sum = 0;
FOR(i,1,m+1,1)cin>>arr[i], sum+=arr[i];
longitud = n-sum;
if((m+1)*(d-1)+sum<n){cout<<"NO"<<endl; return 0;}else{cout<<"YES"<<endl;}
FOR(i,1,m+1,1){
    int aux = 0;
    while(longitud!=0 && aux<d-1){
        cout<<0<<" ";
        aux++;
        longitud--;
        
    }
    FOR(j,1,arr[i]+1,1){
        cout<<i<<" ";
    }
}

while(longitud--){
    cout<<0<<" ";
}
cout<<endl;
return 0;
}