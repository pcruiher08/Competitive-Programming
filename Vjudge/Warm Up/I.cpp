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
    int x, y, level;
    
    bool operator <(const point& pt) const{
        return /*(x < pt.x) || ((!(pt.x < x)) && (y < pt.y)) && */(level < pt.level);
    }
    
};

int main(){
sync;
int n; cin>>n;
point points[n];
FOR(i,0,n,1){
    cin>>points[i].x>>points[i].y;
    points[i].level = max(points[i].x,points[i].y);
}
sort(points, points+n);

point pos; 
pos.x=0; 
pos.y=0;
pos.level = 0;

int sumOfDistance = 0; 

FOR(i,0,n,1){
    sumOfDistance+=abs(points[i].x-pos.x);
    sumOfDistance+=abs(points[i].y-pos.y);
    pos = points[i];
}
cout<<sumOfDistance<<endl;


return 0;
}