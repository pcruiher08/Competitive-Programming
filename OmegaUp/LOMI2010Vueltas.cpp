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

int main(){
sync;
int r,c; cin>>r>>c; 

int matA[r][c];
FOR(i,0,r,1)FOR(j,0,c,1)cin>>matA[i][j];
int n; cin>>n;

int matB[r][c];
int matC[r][c];
int matD[r][c];

FOR(i,0,r,1)FOR(j,0,c,1)matB[i][j] = matA[r-i-1][j], matC[i][j] = matA[i][c-j-1], matD[i][j] = matA[r-i-1][c-j-1];
FOR(i,0,r,1)FOR(j,0,c,1)matD[i][j] = matB[i][c-j-1];

int hs = 0, vs = 0;

while(n--){
    char query; cin>>query;
    if(query == 'H')hs++;
    if(query == 'V')vs++;
}

if(!(hs&1) && !(vs&1)){
    FOR(i,0,r,1){
        FOR(j,0,c,1)cout<<matA[i][j]<<" ";cout<<endl;
    }
}else if(!(hs&1) && vs&1){
    FOR(i,0,r,1){
        FOR(j,0,c,1)cout<<matB[i][j]<<" ";cout<<endl;
    }
}else if(hs&1 && !(vs&1)){
    FOR(i,0,r,1){
        FOR(j,0,c,1)cout<<matC[i][j]<<" ";cout<<endl;
    }
}else{
    FOR(i,0,r,1){
        FOR(j,0,c,1)cout<<matD[i][j]<<" ";cout<<endl;
    }
}
return 0;
}


/*
3 5
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24
1
H


3 5
10 11 12 13 14
15 16 17 18 19
20 21 22 23 24
1
V
*/