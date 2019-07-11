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
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

void pinta(bool manchados[], int inicio, int final){
    ROF(i,final, inicio, 1){
        manchados[i] = true;
    }
}

int main(){
sync;
int n; cin>>n;
int cuenta = 0, lec;
vi fuerzas;
bool personas[n];
memset(personas,false,sizeof(personas));
FOR(i,0,n,1)cin>>lec,fuerzas.pb(lec);
reverse(fuerzas.begin(),fuerzas.end());
FOR(i,0,n,1){
    FOR(j,i+1,fuerzas[i]+i+1,1){
        personas[j] = true;
    }
}

FOR(i,0,n,1)cuenta+=(!personas[i]);
cout<<cuenta<<endl;
return 0;
}