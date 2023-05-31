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
vector<int> listas[6000];

int main(){
sync;

int n; cin>>n;


FOR(i,0,2 * n,1){
    int lec; 
    cin>>lec;
    listas[lec].pb(i);
}

FOR(i,0,5000,1){
    if(listas[i].size() % 2 != 0){
        cout<<-1<<endl;
        return 0;
    }
}

FOR(i,0,5000,1){
    int lec = listas[i].size();
    FOR(j,0,lec,2){
        cout<<listas[i][j]+1<<" "<<listas[i][j+1]+1<<endl;
    }
}

return 0;
}