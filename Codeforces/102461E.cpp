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
#define ull long long
#define FOR(m,s,n,u) for(ull m=s; m<n; m+=u)
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


struct cards{
    ull fenwickTop;
    ull fenwickBot;
    ull a; 
    ull b;
    ull id;
    ull aporte = 0;
};

bool minimos(cards x, cards y){
    return x.a<y.a;
}

bool maximos(cards x, cards y){
    return x.b<y.b;
}

bool ids(cards x, cards y){
    return x.id < y.id;
}



int main(){
sync;
ull n,maximo; 
cin>>n>>maximo; 
    vector<cards> v; 
FOR(i,0,n,1){
    int x,y;

    cin>>x>>y; 
    cards c; 
    c.a = x; 
    c.b = y;
    c.id = i;
    c.fenwickBot = x; 
    c.fenwickTop = y;
    v.pb(c);
}
sort(v.begin(),v.end(),minimos);

FOR(i,1,n,1){
v[i].fenwickBot+=v[i-1].fenwickBot;
v[i].fenwickTop+=v[i-1].fenwickTop;
}
ull buscaTope = 0; 
vector<cards> v2;
vector<cards> respuesta;

while(v[buscaTope].fenwickBot<maximo && buscaTope<n){v2.pb(v[buscaTope++]);};
FOR(i,buscaTope,n,1){respuesta.pb(v[i]);}

//sort(v2.begin(),v2.end(),maximos);

ull suma = 0; 

FOR(i,0,v2.size(),1){
    if(suma+v2[i].b<=maximo){
        suma+=v2[i].b;
        v2[i].aporte = suma - (suma - v2[i].b);
        //cout<<"aporte del id #"<<v2[i].id<<" es: "<<v2[i].aporte<<endl;
        respuesta.pb(v2[i]);
    }else if(suma+v2[i].b>maximo){
        v2[i].aporte = maximo - suma;
        suma += v2[i].aporte;
        //cout<<"aporte del id #"<<v2[i].id<<" es: "<<v2[i].aporte<<endl;
        respuesta.pb(v2[i]);
    }else{
        respuesta.pb(v2[i]);
    }
}
/*
3 40
1 999
10 17
11 16
*/
sort(respuesta.begin(), respuesta.end(), ids);
cout<<suma<<endl;
FOR(i,0,n,1)cout<<respuesta[i].aporte<<" ";
return 0;
}