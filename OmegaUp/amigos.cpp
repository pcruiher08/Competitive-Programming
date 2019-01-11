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

struct amigo{
    string nombre; 
    int id;
    vi friendsIDs;
};

int main(){
sync;
int n; cin>>n; 
string amigos[n];
//vector<vector<int> >
amigo amigos[n];
FOR(i,0,n,1){cin>>amigos[i].nombre; amigos[i].id=i;}
int arr[n][n];
FOR(i,0,n,1)FOR(j,0,n,1){cin>>arr[i][j]; if(arr[i][j])}
return 0;
}