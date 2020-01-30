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

bool isPrime(int n) {
if (n <= 1) return false;
if (n <= 3) return true;
if (n % 2 == 0 || n % 3 == 0) return false;
for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false;
return true;
}

int main(){
sync;

int n; cin>>n; 
int a = 0,b = 0,c = 0;
while(n--){
    here :
    int k; cin>>k; 
    if(isPrime(k)){
        cout<<"NO"<<endl;
        continue;
    }

    FOR(i,2,sqrt(k),1){
        if(k%i==0){
            a = i;
            b = k/i;
            break;
        }
    }

    if(isPrime(a)&&isPrime(b)){
        cout<<"NO"<<endl;
        goto here;
    }else if(isPrime(a)){
        FOR(i,2,sqrt(b),1){
            if(b%i==0 && i!=a){
                c = i;
                b=b/c;
                //a = c/i;
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl;
                continue;
            }
        }
        //busco b
    }else{
        FOR(i,2,sqrt(a),1){
            if(a%i==0 && i!=b){
                c = i;
                b = b/c;
                //b = c/i;
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl;
                continue;
            }
        }
    }
}



return 0;
}