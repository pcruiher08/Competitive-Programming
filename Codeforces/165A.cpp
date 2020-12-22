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
   bool hasUp = false, hasDown = false, hasLeft = false, hasRight = false;
};

int main(){
sync;

vector<point> points;
int n; cin>>n;
while(n--){
    int a,b; cin>>a>>b;
    point aux;
    aux.x=a;
    aux.y=b;
    points.pb(aux);
}


FOR(i,0,points.size(),1){
    FOR(j,0,points.size(),1){
        if(j!=i){

            if(points[j].x > points[i].x && points[j].y == points[i].y){
                points[i].hasRight = true;
            }

            if(points[j].x < points[i].x && points[j].y == points[i].y){
                points[i].hasLeft = true;
            }

            if(points[j].x == points[i].x && points[j].y < points[i].y){
                points[i].hasDown = true;
            }

            if(points[j].x == points[i].x && points[j].y > points[i].y){
                points[i].hasUp = true;
            }

        }
    }
}
ull count = 0;
FOR(i,0,points.size(),1){
    if(points[i].hasDown + points[i].hasLeft + points[i].hasRight + points[i].hasUp == 4){
        count++;
    }
}

cout<<count<<endl;


return 0;
}