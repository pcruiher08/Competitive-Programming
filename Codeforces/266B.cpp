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

int main(){
sync;
//queue at the school 
//is this even a real problem?
//lectura
int n, t; cin>>n>>t; 
char arr[n];
FOR(i,0,n,1)cin>>arr[i];
//procesamiento TODO
while(t--)
FOR(i,0,n,1){
    if(arr[i]=='B'&&arr[i+1]=='G'){
        arr[i]='G'; 
        arr[i+1]='B';
        i++;
    }
}
FOR(i,0,n,1)cout<<arr[i];
return 0;
}