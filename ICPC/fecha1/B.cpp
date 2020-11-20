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
#include <list>
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
#define min(a,b) a<b?a:b
using namespace std;

struct bato{
    int estacionDeBajada;
    int id;
};

bool func(bato a, bato b){
    return a.estacionDeBajada < b.estacionDeBajada;
}

int main(){
sync;
int n; cin>>n; 
vector<bato> v;
list<int> l;

for(int i=0; i<n; i++){
    int lec; cin>>lec; 
    l.push_back(lec);
    bato aux; 
    aux.estacionDeBajada = lec; 
    aux.id = i;
    v.pb(aux);
}

sort(v.begin(),v.end(),func);

int res1 = 0; 
int res2 = 0;

for(int i=0; i<v.size(); i++){
    int indiceAChecar = v[i].estacionDeBajada;
    int indexDelBato = 0; 
    list<int>::iterator it; 
    int cuenta = 0;
    for(it = l.begin(); it != l.end(); ++it){
        cuenta++;
        if(*it == indiceAChecar){
            indexDelBato = *it;
            break;
        } 
    }

    cout<<l.size()<<endl;
    res1 += cuenta - 1;
    res2 += min(cuenta - 1 , l.size() - cuenta);
    l.erase(it);
}

cout<<res1<<" "<<res2<<endl;

return 0;
}