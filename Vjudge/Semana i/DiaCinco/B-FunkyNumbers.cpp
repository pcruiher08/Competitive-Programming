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
#define MAX 100000
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int gauss(int a){
    return a*(a+1)/2;
}

int n;
int triangulares[MAX];
map<int, int> mapa;
int main(){
    sync;
    cin>>n;
    FOR(i,1,MAX,1){ //guarda triangulares
        ull x = gauss(i);
        if (x >= n) break;
        triangulares[i] = gauss(i);
        mapa[triangulares[i]] = 1;
    }
 
    FOR(i,1,MAX,1)
        if(triangulares[i] < n && mapa[n-triangulares[i]] == 1){
                cout<<"YES"<<endl;
                return 0;
        }
   cout<<"NO"<<endl;
   return 0;
}

 
