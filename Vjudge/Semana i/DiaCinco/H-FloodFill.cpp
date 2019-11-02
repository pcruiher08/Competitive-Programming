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
#define INF INT_MAX
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

//needleman wunsch

int main(){
sync;
int n, x;
cin>>n;
vi a;
FOR(i,0,n,1){
    cin >> x;
    if(a.empty())a.push_back(x);
    else
        if(a[a.size()-1]!=x)a.push_back(x);
}

vi b(a);
reverse(a.begin(), a.end());
n = a.size();
int i, j;
vector<vector <int> > lookupTable(n+1,vi(n+1,0));
FOR(i,1,n+1,1)FOR(j,1,n+1,1){
        lookupTable[i][j]=lookupTable[i-1][j-1];
        if(a[i-1]==b[j-1]){
            lookupTable[i][j] += 1;
        }else{
            lookupTable[i][j] += (-INF);
        }
        lookupTable[i][j]=max(lookupTable[i][j],lookupTable[i-1][j]);
        lookupTable[i][j]=max(lookupTable[i][j],lookupTable[i][j-1]);
    }

cout<<n-(lookupTable[n][n]/2+1)<<endl;
return 0;
}