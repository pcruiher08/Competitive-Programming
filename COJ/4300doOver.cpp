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
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;


void recalcula(pair<int,int> mat[][15], int index){
  ROF(i,0,index,1){
    FOR(i,0,index,1) mat[i][index].first = mat[i+1][index].second + mat[i][index+1].second + mat[i+1][index+1].second  +
                                          mat[i][index-1].second + (i>0?mat[i-1][index-1].second + mat[i-1][index+1].second + mat[i-1][index].second:0) + mat[i+1][index-1].second , cout<<mat[i][index].first<<endl;

    FOR(i,0,index,1) mat[index][i].first = mat[index][i+1].second + 
                                           mat[index+1][i].second + 
                                          mat[index+1][i+1].second  +
                                          mat[index-1][i].second + (i>0?mat[index-1][i-1].second + mat[index+1][i-1].second + mat[index][i-1].second:0)+ mat[index-1][i+1].second , cout<<mat[index][i].first<<endl;
  }                                
}

int main(){
sync;
pair<int, int> mat[15][15];

//num, steps

mat[0][0].first=0;
mat[0][1].first=1;
mat[1][0].first=1;
mat[1][1].first=1;

mat[0][0].second=0;
mat[0][1].second=0;
mat[1][0].second=0;
mat[1][1].second=0;

FOR(i,0,15,1){
  FOR(j,0,15,1){
    cout<<mat[i][j].first;
  }cout<<endl;
}
cout<<endl; 
FOR(i,0,15,1){
  FOR(j,0,15,1){
    cout<<mat[i][j].second;
  }cout<<endl;
}

vector<int> res; 
cout<<endl; 

int sumalos = 0;
int adicion = 1;

while(adicion++ < 15){
  sumalos = 0;
  FOR(i,0,adicion,1){
    FOR(j,0,15,1){
      sumalos += mat[i][j].first;
      //cout<<mat[i];
      mat[i][j].second = mat[i][j].first;
    }//cout<<endl;
  }
  cout<<sumalos;
  recalcula(mat, adicion);
}

return 0;
}