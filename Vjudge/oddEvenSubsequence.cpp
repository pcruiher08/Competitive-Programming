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

int arreglo[200005];
int n, k;

bool revisa(int aim, int bit){
    int res = 0; 
    FOR(i,1,n+1,1){
        if(!bit){
            res++; 
            bit = !bit;
        }else{
            if(arreglo[i] <= aim){
                res++; 
                bit = !bit;
            }
        }
    }
    return res >= k;

}

int main(){
sync;

cin>>n>>k;

FOR(i,1,n+1,1)cin>>arreglo[i];

int izquierda = 1; int derecha = mod;
while(izquierda<derecha){
    int centro = (izquierda+derecha)/2;
    if( revisa(centro,0) || revisa(centro,1) ){
        derecha = centro;
    }else{
        izquierda = centro + 1;
    }
}
cout<<izquierda<<endl;

return 0;
}