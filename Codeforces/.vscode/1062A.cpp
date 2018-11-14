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

int n; 
cin>>n; 
int arr[n];
FOR(i,0,n,1)cin>>arr[i];
int cont = 0; 

if(arr[0]==1&&arr[1]==2)cont+=2,arr[0]=-1;
if(arr[n-1]==1000&&arr[n-2]==999)cont+=2, arr[n-1]=1001;

FOR(i,1,n-1,1)if(arr[i-1]+1==arr[i]&&arr[i+1]-1==arr[i]) cont++;

cout<<cont;
return 0;
}

/*
6
1 3 4 5 6 9

*/
