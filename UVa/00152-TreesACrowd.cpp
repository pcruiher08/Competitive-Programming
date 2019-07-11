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
#define ALL(x) x.begin(),x.end()
using namespace std;

struct point{
    int x,y,z;
    int distancia1, distancia2;
    bool operator < (point other) const { 
        if(x>other.x)
            return x < other.x; 
        else if(y>other.y)
            return y < other.y; 
        else   
            return z < other.z;
        } 
         
};


float distance(point a, point b){
    return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y) + (a.z-b.z) * (a.z-b.z));
}

int distancias[100000000];

int main(){
sync;

vector<point> points;
int a = 1,b = 1,c = 1; 
while(1){

    cin>>a>>b>>c;
    if(a==0&&b==0&&c==0)break;

    point aux; 
    aux.x = a; 
    aux.y = b; 
    aux.z = c; 
    points.pb(aux);

}
sort(ALL(points));


//FOR(i,0,points.size(),1)cout<<points[i].x<<" "<<points[i].y<<" "<<points[i].z<<endl;



FOR(i,0,points.size(),1){
  double dist = (i==0?distance(points[0],points[1]):distance(points[i], points[i-1]));
  distancias[(int)floor(dist)]++;
}


//

FOR(i,0,10,1)cout<<distancias[i]<<" ";
cout<<endl;

/*
10 10 0
10 10 0
10 10 1
10 10 3
10 10 6
10 10 10
10 10 15
10 10 21
10 10 28
10 10 36
10 10 45
0 0 0

*/

return 0;
}