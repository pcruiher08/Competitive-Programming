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

struct point{
    int x, y;
    bool operator <(const point& pt) const{
        return (x < pt.x) || ((!(pt.x < x)) && (y < pt.y));
    }
};

int main(){
sync;
set<point> points;

int n, k;
cin>>n>>k; 

while(n--){
    point aux; 
    cin>>aux.x; 
    cin>>aux.y;
    points.insert(aux);
}

while(k--){
    int tam = points.size();

    point aux; 
    cin>>aux.x; 
    cin>>aux.y; 

    points.insert(aux);

    if(points.size() == tam){
        cout<<0<<endl;
    }else{
        cout<<1<<endl;
    }
}
return 0;
}