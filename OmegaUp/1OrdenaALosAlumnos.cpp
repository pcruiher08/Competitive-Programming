#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
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
  ll alumnos[n];
  FOR(i,0,n,1) cin>>alumnos[i];
  sort(alumnos,alumnos+n);
  FOR(i,0,n,1) cout<<alumnos[n-1-i]<<" ";
}