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

struct point{
   int x, y;
};

bool ordY(point a, point b){
    return a.y < b.y;
}

bool ordX(point a, point b){
    return a.x < b.x;
}

int main(){
sync;


int n; cin>>n;
vector<point> enX;
vector<point> enY;

FOR(i,0,n,1){
    int x,y;
    cin>>x>>y;
    point aux;
    aux.x = x;
    aux.y = y;
    enX.pb(aux);
    enY.pb(aux);
}
sort(enX.begin(),enX.end(),ordX);
sort(enY.begin(),enY.end(),ordY);

point test;
test.x = 1;
test.y = 5;

auto it=std::lower_bound(begin(enY), end(enY), test , ordY);
cout<<it - enY.begin()<<endl;


return 0;
}