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

struct valores{
    int a; 
    int g; 
    int indice;
    char eleccion;
};

bool ordenaG(valores a, valores b){
    return a.g < b.g;
}

bool ordenaIndice(valores a, valores b){
    return a.indice < b.indice;
}


int main(){
sync;

vector<valores> fila;
int n;
cin>>n;

long long acumA = 0;
long long acumG = 0;

FOR(i,0,n,1){
    int a, g;
    cin>>a>>g;
    valores aux; 
    aux.a = a;
    aux.g = g;
    aux.indice = i;
    aux.eleccion = 'A';
    acumA += a;
    fila.pb(aux);
}

sort(fila.begin(), fila.end(), ordenaG);
int iterador = 0;
while(abs(acumA - acumG) > 500 && iterador < n){    
    acumG += fila[iterador].g;
    acumA -= fila[iterador].a;
    fila[iterador].eleccion = 'G';
    iterador++;
}

sort(fila.begin(), fila.end(), ordenaIndice);
FOR(i,0,n,1)cout<<fila[i].eleccion;


return 0;
}