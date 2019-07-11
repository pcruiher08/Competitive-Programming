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

bool p[1000001];
void sieve(){
int n = 1000000;
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
sieve();
int n; 
cin>>n; 
int x;
while(n--){
    cin>>x;
    cout<<(prime(x)?"SI":"NO")<<endl;
}

return 0;
}