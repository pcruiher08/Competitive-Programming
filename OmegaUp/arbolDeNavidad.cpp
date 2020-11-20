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
void printEsapcios(int espacios){
    FOR(i,0,espacios,1){
        cout<<" ";
    }
    return;
}

void printEstrellas(int cuantasEstrellas){
    FOR(i,0,cuantasEstrellas,1){
        cout<<"*";
    }
    cout<<endl;
    return;
}
 
void printTronco(int espacioTronco){
    printEsapcios(espacioTronco);
    cout<<"###\n";
}

int main(){
sync;
int n; cin>>n;
int espacios = n - 1;
int cuantasEstrellas = 1;
int nivel = 0 ;

while(nivel != n){
    printEsapcios(espacios--);
    printEstrellas(cuantasEstrellas);
    cuantasEstrellas+=2;
    nivel++;
}

int espacioTronco = cuantasEstrellas/2  - 2;
printTronco(espacioTronco);
printTronco(espacioTronco);


return 0;
}