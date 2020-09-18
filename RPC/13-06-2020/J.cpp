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
#define pdd pair<double,double>
using namespace std;

struct point{
   int x, y;
   bool operator <(const point& pt) const{
       return (x < pt.x) || ((!(pt.x < x)) && (y < pt.y));
   }
};

int main(){
sync;
int n; 
cin>>n;
vector<pdd> vec; 
double den = 0;
double vel = 0; 
double aux = 0.0; 

FOR(i,0,n,1){
    double Ti; 
    double Si; 
    double Ai; 
    cin>>Ti>>Si>>Ai;
    den += max((double)0,Ti-Si*min(Ai,2*PI-Ai));
    double minimo = min(PI, Ti/Si);
    double aux1 = Ai - minimo;
    double aux2 = Ai + minimo;

    if(aux1 < 0){
        vel = vel + Si; 
        aux1 = aux1 + 2*PI;
    }

    if(aux2 > 2*PI){
        vel = vel - Si;
        aux2 = aux2 - 2*PI;
    }

    vec.pb({aux1,Si});
    vec.pb({Ai,-2*Si});
    vec.pb({aux2,Si});
}
sort(vec.begin(),vec.end());
double res = den; 

FOR(i,0,vec.size(),1){
    den += vel * (vec[i].first - aux);
    res = max(res, den);
    aux = vec[i].first;
    vel += vec[i].second;   
}
cout<<fixed<<setprecision(6)<<res<<endl;
return 0;


}