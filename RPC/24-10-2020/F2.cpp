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

int main(){
sync;
int n, k, res = INF; cin>>n>>k; 
int adj[n][n], distancias[n][n];
FOR(i,0,n,1)FOR(j,0,n,1)distancias[i][j] = INF;

deque<int> q; 

FOR(i,0,n,1)FOR(j,0,n,1){
    int lec; cin>>lec;
    lec--;
    adj[i][j] = lec;
    if(lec == 0){
        q.push_back(i);
        q.push_back(j);
        distancias[i][j] = 0;
    }
    
}


while(!q.empty()){
    int xCoord = q.front(); q.pop_front();
    int yCoord = q.front(); q.pop_front();

    if(adj[xCoord][yCoord] == k - 1){
        res = min(res, distancias[xCoord][yCoord]);
    }

    FOR(i,0,n,1)FOR(j,0,n,1){
        if(adj[i][j] != adj[xCoord][yCoord] + 1){
            continue;
        }
        if(distancias[i][j] == INF){
            q.push_back(i);
            q.push_back(j);
        }
        distancias[i][j] = min(distancias[i][j], abs(xCoord - i) + abs(yCoord - j) + distancias[xCoord][yCoord]);
    }

}

if(res == INF){
    cout<<-1<<endl;
}else{
    cout<<res<<endl;
}


return 0;
}