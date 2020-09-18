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

struct datos{
    int inicio,fin; char id;
};

bool func(datos a, datos b){
    if(a.inicio != b.inicio){
        return a.inicio < b.inicio;
    }
    if(a.fin != b.fin){
        return a.fin < b.fin;
    }

    return a.id < b.id;

}

int main(){
sync;

int n; cin>>n;
vector<datos> vec;

FOR(i,0,n,1){
    char lecID; 
    int lecInicio, lecFin, duracion, wireNumber;
    cin>>lecID>>lecInicio>>duracion>>wireNumber;
    datos aux;
    aux.inicio = lecInicio - wireNumber;
    aux.fin = 1;
    aux.id = lecID;

    datos aux2;
    aux2.inicio = lecInicio - wireNumber + duracion;
    aux2.fin = -1;
    aux2.id = lecID;

    vec.pb(aux);
    vec.pb(aux2);
}

sort(vec.begin(),vec.end(),func);

/*
FOR(i,0,vec.size(),1){
    cout<<vec[i].inicio<<" "<<vec[i].fin<<" "<<vec[i].id<<endl;
}
*/

ll respuesta = 0 ;
ll cuentaH = 0, cuentaV = 0 ;
ll cuenta = 0;
FOR(i,0,vec.size(),1){
    //cout<<++cuenta<<endl;
    if (vec[i].id == 'h') {
        cuentaH += vec[i].fin ;
        if (vec[i].fin > 0) {
            respuesta += cuentaV ;
        }
    } else {
        cuentaV += vec[i].fin ;
        if (vec[i].fin > 0)
            respuesta += cuentaH ;
    }
}

cout << respuesta << endl ;

return 0;
}

/*
7
v 1 3 1
v 1 15 2
h 4 5 1
h 5 5 2
h 6 5 3
h 7 5 4
h 8 5 5
*/