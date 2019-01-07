#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
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
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

struct persona{
    string nombre;
    string apellido;
    int id; 
    float estatura;
    int peso;
};

bool func(persona a, persona b){
    return (a.peso/(a.estatura*a.estatura)>=b.peso/(b.estatura*b.estatura));
}

int main(){
sync;
int n; 
cin>>n;
vector<persona> personas;
persona aux;
FOR(i,0,n,1){cin>>aux.id; cin>>aux.nombre; cin>>aux.apellido; cin>>aux.peso; cin>>aux.estatura; personas.pb(aux);}
sort(personas.begin(), personas.end(), func);
FOR(i,0,n,1){cout<<personas[i].id<<" "<<personas[i].nombre<<" "<<personas[i].apellido<<" "; cout<<fixed<<setprecision(1)<<personas[i].peso/(personas[i].estatura*personas[i].estatura)<<endl;}
}