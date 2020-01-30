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

#define max(a,b) a>b?a:b


ull gcd(ull a,ull b){
   return b==0 ? a : gcd(b,a%b);
}

ull lcm(ull a,ull b){
   return (a*b)/gcd(a,b);
}


int main(){
sync;

ull n; 
cin>>n; 

ull minimoA = n, minimoB = 1;

FOR(i,1,sqrt(n),1){
  if(n/i == floor(n/i) && n/i != n && lcm(n/i, i) == n){
      if(max(i,n/i) < max(minimoA,minimoB)){
          minimoA = i; 
          minimoB = n/i;
      }
  }  
}

cout<<minimoA<<" "<<minimoB<<endl;


return 0;
}