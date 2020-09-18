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
vector<int> primos;
bool p[1000001];
int tope = 1000001;
void sieve(){
    primos.pb(2);
    FOR(i,0,tope,1)p[i] = 1;
    for(int i=3; i<sqrt(tope); i+=2)if(p[i])for(int j=i*i; j<tope; j+=i*2)p[j]=0;
    FOR(i,3,tope,2)if(p[i])primos.pb(i);
}


int main(){
sync;
sieve();

int n; 
int caso = 0; 

while(cin>>n){
    if(n == 0) return 0;
    int back = 0;
    FORb(i,0,primos.size(),1,n>2*primos[i]){
		int diff = n - primos[i];
		int izquierda = i + 1;
        int derecha = primos.size()-1;
        int aux = i;
		while(izquierda <= derecha){
			int centro = (izquierda + derecha)/2;
			if (primos[centro] <= diff){
				izquierda = centro + 1;
                aux = centro;
            }else{
                derecha = centro - 1;
            }
		}
		back += aux - i;
	}
    caso++;

    cout<<"Case "<<caso<<": "<<back<<endl;
}


return 0;
}