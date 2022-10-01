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

struct coefs{
    int a = 1, b = 1;
    int howManyPrimes = 0; 
    int coef = 1;
};

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


/**
 * Checks if a value is prime in O(log^3 N) time using a deterministic implementation of the Miller-Rabin algorithm
 * This code only works for values less than 2^64, and requires __int128
 * Written by Brett Hale (StackOverflow 24096332)
 * @param n The value that will be tested
 * @return True if n is prime, and false if n is composite
 */
bool IsPrime (unsigned long long int n) {
	if(n == 1) {
		return 0;
	}
	const unsigned long long int sprp32_base[] = {2, 7, 61, 0};
	const unsigned long long int sprp64_base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022, 0};
	const unsigned long long int *sprp_base;
	if((n & 1) == 0) {
		return n == 2;
	}
	sprp_base = (n <= 4294967295U) ? sprp32_base : sprp64_base;
	for(; *sprp_base != 0; sprp_base++) {
		unsigned long long int a = *sprp_base, m = n - 1, r, y, s = 1;
		while ((m & (1UL << s)) == 0) {
			s++;
		}
		r = m >> s;
		if ((a %= n) == 0) {
			continue;
		}
		unsigned __int128 u = 1, w = a;
		while (r != 0) {
			if ((r & 1) != 0) {
				u = (u * w) % n;
			}
			if ((r >>= 1) != 0) {
				w = (w * w) % n;
			}
		}
		if ((y = (unsigned long long int)u) == 1) {
			continue;
		}
		for (unsigned long long int j = 1; j < s && y != m; j++) {
			u = y;
			u = (u * u) % n;
			if ((y = (unsigned long long int)u) <= 1) {
				return false;
			}
		}
		if(y != m) {
			return false;
		}
	}
	return true;
}


int countPrimes(int a, int b, vector<coefs> &vectorOfCoefs){
    int n = 0; 
    int primeCounter = 0;
    while( IsPrime(n * n + a * n + b) ){
        primeCounter++;
        //cout<<"primecounter "<<primeCounter<<endl;
        n++;
    }

    coefs add;
    add.a = a;
    add.b = b;
    add.howManyPrimes = primeCounter;
    add.coef = a * b;

    vectorOfCoefs.push_back(add);
}

bool ordFunc(coefs primero, coefs segundo){
    return primero.howManyPrimes > segundo.howManyPrimes;
}

int main(){
sync;

sieve(1000000);

vector<coefs> vectorOfCoefs;

for(int a = -999; a < 1000; a++){
    for(int b = -1000; b <= 1000; b++){
        //cout<<"computing for "<<a<<" and "<<b<<endl;
        countPrimes(a,b,vectorOfCoefs);
    }
}

sort(vectorOfCoefs.begin(), vectorOfCoefs.end(), ordFunc);
cout<<"n^2+("<<vectorOfCoefs[0].a<<")n+"<<vectorOfCoefs[0].b<<endl;

cout<<"howManyPrimes = " << vectorOfCoefs[0].howManyPrimes<<endl;
cout<<"coefficient = " << vectorOfCoefs[0].coef<<endl;
vector<coefs> test; 
countPrimes(-79,  1601, test);
cout<<test[0].howManyPrimes<<endl;

return 0;
}