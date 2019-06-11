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

void fastscan(int &x){
    char ch; bool f= 0; int a=0;
    while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));
    if(ch!='-')a*=10,a+=ch-'0';else f=1;
    while(((ch=getchar())>='0')&&(ch<='9'))a*=10, a+=ch-'0';
    if(f)a=-a;x=a;
}

int main(){
sync;
int n; fastscan(n);
pair<int,int> mat[16][16];
FOR(i,0,16,1){
    FOR(j,0,16,1){
        if(i==0)mat[i][j] = make_pair(1,j+1);
        else{
            if(j==0) mat[i][j] = make_pair(1,1);
            else mat[i][j] = make_pair(mat[i-1][j].second,mat[i-1][j].second + mat[i][j-1].second);
        }
    }
}

/*
FOR(i,0,16,1){
    FOR(j,0,16,1){
        cout<<mat[i][j].first<<" ";
    }cout<<endl;
}
cout<<endl;

*/
mat[1][1].first ++;

FOR(i,2,16,1){
    FOR(j,2,16,1){
        if(j>i)mat[i][j].first += mat[i-1][j].first;
        if(j<i)mat[i][j].first += mat[i][j-1].first;
    }
}

FOR(i,2,16,1)mat[i][i].first += (mat[i-1][i].first + mat[i][i-1].first + mat[i-1][i-1].first);
/*
FOR(i,0,16,1){
    FOR(j,0,16,1){
        cout<<mat[i][j].first<<" ";
    }cout<<endl;
}
cout<<endl;
*/

vector<int> res; 

FOR(i,0,16,1)res.pb(mat[i][i].first);

//FOR(i,0,16,1)cout<<res[i]<<endl;

/*
FOR(i,0,16,1){
    FOR(j,0,16,1){
        cout<<mat[i][j].second<<" ";
    }cout<<endl;
}
cout<<endl;
*/


while(n--){
    int query; fastscan(query);
    cout<<res[query]<<endl;
}
return 0;
}