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

/**
 * Calculates and stores all primes less than or equal to the limit in O(N) time
 * @param primes An array where all the primes less than or equal to the limit shall be stored
 * @param limit The largest value that will be checked by the function
 * @return The amount of primes that are stored in the array of primes
 */
int SieveOfAtkin(long long int* primes, long long int limit) {
    int index = 0;
    limit++;
    if(limit < 3) {
        return index;
    }
    primes[index] = 2;
    index++;
    if(limit < 4) {
        return index;
    }
    primes[index] = 3;
    index++;
    bool* sieve = new bool[limit];
    for(long long int i = 0; i < limit; i++) {
        sieve[i] = false;
    }
    for(long long int i = 1; i * i < limit; i++) {
        for(long long int j = 1; j * j < limit; j++) {
            long long int a = 4 * i * i + j * j;
            long long int b = 3 * i * i + j * j;
            long long int c = 3 * i * i - j * j;
            if(a <= limit && (a % 12 == 1 || a % 12 == 5)) {
                sieve[a] = !sieve[a];
            }
            if(b <= limit && b % 12 == 7) {
                sieve[b] = !sieve[b];
            }
            if(c <= limit && i > j && c % 12 == 11) {
                sieve[c] = !sieve[c];
            }
        }
    }
    for(long long int i = 5; i * i < limit; i++) {
        if(sieve[i]) {
            for(long long int j = i * i; j < limit; j += i * i) {
                sieve[j] = false;
            }
        }
    }
    for(long long int i = 5; i < limit; i++) {
        if(sieve[i]) {
            primes[index] = i;
            index++;
        }
    }
    return index;
}

int main(){
sync;
long long int primes[79000];
int cuantosPrimos = SieveOfAtkin(primes,79000);

int n; cin>>n;

while(n--){
    int k; cin>>k;
    vi res;
    FOR(i,1,200,1){
        //cout<<"primo: "<<primes[i]<<endl;
        //cout<<"calc " << (1<<primes[i]) << " " << ((1<<primes[i]) + k) << " "<<endl;
        if( ((1<<primes[i]) + k) % primes[i] == 0 ){
            res.pb(primes[i]);
            cout<<"entro > "<<primes[i]<<endl;
        }
    }
    if(res.size()){
        FOR(i,0,res.size(),1){
            cout<<res[i]<<" ";
        }cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}

return 0;
}