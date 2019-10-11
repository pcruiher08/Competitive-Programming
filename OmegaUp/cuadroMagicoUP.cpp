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

int cuadroMagico[1000][1000];
 
int main(){
    int n; cin>>n;
    int contador = 1;
    FOR(i,0,n,1)FOR(j,0,n,1)cuadroMagico[i][j] = 0;
    int prim = 0, sec = n/2;
    cuadroMagico[0][n/2] = 1;
 
    while(contador < n*n){
        contador++;
        if(prim-1>=0)
            if(sec+1<n)
                if(cuadroMagico[prim-1][sec+1]==0)cuadroMagico[--prim][++sec] = contador;
                else cuadroMagico[++prim][sec] = contador;
            else
                if(cuadroMagico[prim-1][0]==0)sec = 0,cuadroMagico[--prim][sec] = contador;
                else cuadroMagico[++prim][sec] = contador;
        else
            if(sec+1<n)
                if (cuadroMagico[n-1][sec+1]==0)prim = n-1,cuadroMagico[prim][++sec] = contador;
                else cuadroMagico[++prim][sec] = contador;  
            else cuadroMagico[++prim][sec] = contador;  
    }
    FOR(i,0,n,1){FOR(j,0,n,1){cout<<cuadroMagico[i][j]<<" ";}cout<<endl;}

}
 