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
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;
int mat[101][101];
int main(){
sync;


    int x1,y1; cin>>x1>>y1;
    int x2,y2; cin>>x2>>y2;
    mat[x1][y1] = 1;
    mat[x2][y2] = 1; 
    mat[x2][y1] = 1; 
    mat[x1][y2] = 1; 




    int x3,y3; cin>>x3>>y3;
    int x4,y4; cin>>x4>>y4;
    mat[x3][y3] = 2;
    mat[x4][y4] = 2; 
    mat[x4][y3] = 2; 
    mat[x3][y4] = 2; 
bool hay = false;


FOR(i,min(x1,x2),max(x1,x2)+1,1){
    FOR(j,min(y1,y2),max(y1,y2)+1,1){
        if(mat[i][j]==2){ hay = true;
        cout<<"SI"<<endl; return 0;}
    }
}


 

FOR(i,min(x3,x4),max(x3,x4)+1,1){
    FOR(j,min(y3,y4),max(y3,y4)+1,1){
        if(mat[i][j]==1){ hay = true;
        cout<<"SI"<<endl; return 0;}
    }
}

cout<<"NO"<<endl;

//xyxyxyxyxy



return 0;
}