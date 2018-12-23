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
/*

int cambiaABits[16] =  {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4}; 

unsigned ll cuentaDigitos(ull n){ 
   ll resto = 0; 
   if (0 == n) 
      return cambiaABits[0]; 
   resto = n & 0xf; 
   return cambiaABits[resto] + cuentaDigitos(n>>4); 
} 
*/

int main(){
sync;
ull n; 
cin>>n; 
ull sum = 0; 
for(ull i = 0; i<n/2+1; i++) sum+=__builtin_popcount (i);
//cout<<cuentaDigitos(n);
cout<<sum<<endl;
return 0;
}