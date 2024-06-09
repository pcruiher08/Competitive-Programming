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
    int x; int y;
};

int main(){
sync;

int n; cin>>n;
while(n--){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    point p1, p2, p3;
    p1.x = a;
    p1.y = b;    
    p2.x = c;
    p2.y = d;    
    p3.x = e;
    p3.y = f;
    //sign of z component of cross product between line from p1 to p2, and point p3
    //WA

    double sign = ((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x));

    if(sign == 0){
        cout<<"TOUCH"<<endl;
    }else if(sign > 0){
        cout<<"LEFT"<<endl;
    }else{
        cout<<"RIGHT"<<endl;
    }

}
return 0;
}