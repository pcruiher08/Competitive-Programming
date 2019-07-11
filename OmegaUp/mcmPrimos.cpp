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

ll gcd(ll a,ll b){
    return b==0 ? a : gcd(b,a%b);
}

vector<int> primos; 
bool p[1000001];
void sieve(int n){
  for(int i=2; i<sqrt(n); i++){
    if(!p[i]){
      for(int j=i*i; j<n; j+=i){
        p[j]=true;
      }
    }
  }
}

bool prime(int a){
    return !p[a];
}

int main(){
sync;
int a, b; 
cin>>a>>b; 
int mcd = gcd(a,b);
cout<<mcd<<endl;
int toC; 
if(mcd&1)toC = a; else toC = b;
sieve(toC+1);
FOR(i,2,toC+1, 1){
    if(prime(i))cout<<i<<" ";
}

return 0;
}