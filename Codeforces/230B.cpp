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

bool isPrime(int n) { 
    if (n <= 1) return false; 
    if (n <= 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; 
    return true; 
} 
  
bool tPrime(long long n) { 
    int raiz = (int)sqrt(n); 
    if(1LL * raiz * raiz != n) return false; 
    return isPrime(raiz); 
} 

int main(){
sync;
int n; cin>>n; 
ull k; 
while(n--){
cin>>k; 
cout<<(tPrime(k)?"YES":"NO")<<endl;
}

return 0;
}