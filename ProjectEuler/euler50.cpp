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

struct cribaOpt{
    int fen;
    int value;
};

vector<cribaOpt> primos;

ull criba[10000];
void sieve(){
	FOR(i,2,10000,1)if(!criba[i])FOR(j,i*i,10000,i)++criba[j]; 
    FOR(i,2,10000,1) if(!criba[i]){cribaOpt aux; aux.value = i; aux.fen=i; primos.pb(aux);} 
}


int main(){
sync;
sieve();
FOR(i,1,primos.size(),1)primos[i].fen += primos[i-1].fen;


cout<<primos[primos.size()-1].value<<endl;
return 0;
}