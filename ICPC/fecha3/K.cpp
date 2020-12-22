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
#include <unordered_map>
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
const int N = 100001;
void fastscan(int &x){
   char ch; bool f= 0; int a=0;
   while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));
   if(ch!='-')a*=10,a+=ch-'0';else f=1;
   while(((ch=getchar())>='0')&&(ch<='9'))a*=10, a+=ch-'0';
   if(f)a=-a;x=a;
}

ll power(ll x, int y, int p){
    ll res = 1;
 
    x = x % p; 
    while (y > 0){

        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
ll modInverse(ll n, int p){
    return power(n, p - 2, p);
}
 
ll fac[100001];

ll mi[100001];

inline size_t key(int i,int j) {return (size_t) i << 32 | (unsigned int) j;}

unordered_map<size_t, int> um;

ll nCrModPFermat(ll n, ll r, ll p){
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    if( um.find(key(n,r)) == um.end()){
        um[key(n,r)] =  (fac[n] * modInverse(fac[r],mod) % p * modInverse(fac[n-r],mod) % p)% p;
    }
    return um[key(n,r)];
}

// Returns nCr % p 
int nCrModP(int n, int r, int p) 
{ 
    // Optimization for the cases when r is large 
    if (r > n - r) 
        r = n - r; 
  
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    int C[r + 1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (int i = 1; i <= n; i++) { 
  
        // Fill entries of current row using previous 
        // row values 
        for (int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j - 1]) % p; 
    } 
    return C[r]; 
} 

// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];
 
// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];
 
// array to store factorial of first N numbers
ll fact[N + 1];
 
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
 
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}
 
ll l[10001][10001] = { 0 }; 
  
int initialize() 
{ 
  
    // 0C0 = 1 
    l[0][0] = 1; 
    for (int i = 1; i < 10001; i++) { 
        // Set every nCr = 1 where r = 0 
        l[i][0] = 1; 
        for (int j = 1; j < i + 1; j++) { 
  
            // Value for the current cell of Pascal's triangle 
            l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]) % mod; 
        } 
    } 
} 
  
// Function to return the value of nCr 
int nCr(int n, int r) 
{ 
    // Return nCr 
    return l[n][r]%mod; 
}
int main(){
sync;

int n; cin>>n;

while(n--){
    int A,B,C,K,c;
    fastscan(A);
    fastscan(B);
    fastscan(C);
    fastscan(K);
    fastscan(c);
    initialize();

    
    ll producto = nCr(C,c);

    ll sumas = 0;



    ll resta = K - c;

    //considerar el caso donde A+B+C < K, regresar 0
    //considerar el caso donde A+B < K - c, regresar 0
    for(int i = 1; i < resta - 1; i++){
        if(i <= A && resta - i <= B){
            //cout<<i<<" " << resta - i<<endl;
            ll izq = i;
            ll der = resta - i;
            //cout<<nCk(A,izq,mod) * nCk(B,der,mod) <<endl;
            if(der + izq == resta)
            sumas += (nCr(A,izq) * nCr(B,der))%mod;
        }

    }

    cout<<MOD((sumas%mod) * (producto%mod))<<endl;
}
return 0;
}