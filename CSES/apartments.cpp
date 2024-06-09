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
int n, m, k; cin>>n>>m>>k;

vector<int> desired; 
FOR(i,0,n,1){
    int lec; cin>>lec; 
    desired.push_back(lec);
}

vector<int> apts; 
FOR(i,0,m,1){
    int lec; cin>>lec; 
    apts.push_back(lec);
}

sort(desired.begin(), desired.end(), greater<int>());
sort(apts.begin(), apts.end(), greater<int>());

//FOR(i,0,n,1)cout<<desired[i]<<" ";cout<<endl;
//FOR(i,0,m,1)cout<<apts[i]<<" ";cout<<endl;

int p1 = 0, p2 = 0;

int res = 0;
while(p1 < n && p2 < m){
    //cout<<"checking: "<<desired[p1]<<" with: "<<apts[p2]<<endl;
    bool arriba = desired[p1] - k > apts[p2];
    bool abajo = desired[p1] + k < apts[p2];
    bool enmedio = desired[p1] - k <= apts[p2] && apts[p2] <= desired[p1] + k;
    if(enmedio){
        //cout<<"ENCONTRE"<<endl;
        res++;
        p1++;
        p2++;
    }else if(arriba){
        p1++;
    }else{
        p2++;
    }
}

cout<<res<<endl;



return 0;
}