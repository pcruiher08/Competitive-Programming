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
#define FOR(m,s,n,u) for(int m=s; m<=n; m+=u)
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
int n; cin>>n; 

int mat[5][10*10000+100];
int dP[5][10*10000+100];

/*
3
1 1 1
1 -1 1
1 1 1

7
*/

FOR(i,1,3,1)FOR(j,1,n,1)cin>>mat[i][j];
//FOR(i,0,3,1){FOR(j,0,n,1){cout<<mat[i][j];}cout<<endl;}
dP[3][n]=mat[3][n]; dP[2][n]=mat[3][n]+mat[2][n]; dP[1][n]=mat[1][n]+dP[2][n];
ROF(j,1,n-1,1){
    dP[1][j]=mat[1][j]+max(dP[1][j+1],max(mat[2][j]+dP[2][j+1],max(mat[2][j]+mat[3][j]+dP[3][j+1],mat[1][j+1]+mat[2][j]+mat[2][j+1]+mat[3][j]+mat[3][j+1]+dP[3][j+2])));
    dP[3][j]=mat[3][j]+max(dP[3][j+1],max(mat[2][j]+dP[2][j+1],max(mat[2][j]+mat[1][j]+dP[1][j+1],mat[3][j+1]+mat[2][j]+mat[2][j+1]+mat[1][j]+mat[1][j+1]+dP[1][j+2])));
    dP[2][j]=mat[2][j]+max(dP[2][j+1],max(mat[1][j]+dP[1][j+1],mat[3][j]+dP[3][j+1]));
}
cout<<dP[1][1]<<endl;

return 0;
}