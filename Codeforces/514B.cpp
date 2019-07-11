#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=2; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define pb push_back
#define mod 1000000009
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>

using namespace std;
struct position{
    int x;
    int y;
    double slopeAtSolo=INT_MIN;
};

int main(){
    int troopers;
    cin>>troopers;
    position myPos;
    bool horizontal = false;
    cin>>myPos.x>>myPos.y;
    set <double> cuantos;
    position tPos[troopers];
    for(int i=0; i<troopers; i++){
        cin>>tPos[i].x>>tPos[i].y;
        if(myPos.x!=tPos[i].x){
        tPos[i].slopeAtSolo=(tPos[i].y-myPos.y*1.0)/(tPos[i].x-myPos.x);
        cuantos.insert(tPos[i].slopeAtSolo);
        }else{
            horizontal = true;
        }
    }
    cout<<cuantos.size()+(horizontal?1:0);
}