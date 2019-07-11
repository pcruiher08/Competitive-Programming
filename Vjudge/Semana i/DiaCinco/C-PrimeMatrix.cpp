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
#define FOR(m,s,n,u) for(ull m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(ull m=n; m>=s; m-=u)
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


int mat[1000][1000];

vector<ull> primos;
ull criba[100009];
void sieve(){
	FOR(i,2,100004,1)if(!criba[i])FOR(j,i*i,100004,i)++criba[j]; 
    FOR(i,2,100004,1) if(!criba[i]) primos.pb(i);
}


int main(){
    sync;
	sieve();	
 
	int n,m;
	cin>>n>>m;
    FOR(i,1,n+1,1)FOR(j,1,m+1,1)cin>>mat[i][j];
    FOR(i,1,n+1,1)FOR(j,1,m+1,1) mat[i][j] = *lower_bound(primos.begin(),primos.end(),mat[i][j]) - mat[i][j];

    ull res = INT_MAX;
    FOR(i,1,m+1,1){
        ull aux = 0; 
        FOR(j,1,n+1,1){
            aux+=mat[j][i];
        }
        res=min(res,aux);
    }

    FOR(i,1,n+1,1){
        ull aux = 0; 
        FOR(j,1,m+1,1){
            aux+=mat[i][j];
        }
        res = min(res,aux);
    }
	cout<<res<<endl;
				
	return 0;
}
