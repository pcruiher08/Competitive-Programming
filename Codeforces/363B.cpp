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
int n, k; cin>>n>>k;
int arr[n];
FOR(i,0,n,1)cin>>arr[i];
FOR(i,1,n,1)arr[i]=arr[i - 1] + arr[i];
int minimoIndice = 0;
int minimo = INF;
//FOR(i,0,n,1)cout<<arr[i]<<" ";
//cout<<endl;
FOR(i,0,n - k + 1,1){
    //cout<< (arr[i + k - 1] - (i > 0 ? arr[i - 1] : 0)) << " "<<endl;
    if(minimo > (arr[i + k - 1] - (i > 0 ? arr[i - 1] : 0))){
        minimo = (arr[i + k - 1] - (i > 0 ? arr[i - 1] : 0));
        minimoIndice = i;
        //cout<< (arr[i + k - 1] - (i > 0 ? arr[i - 1] : 0))<<endl;
        //cout<<minimo<<endl;
    }
}
//cout<<endl;
//cout<<minimo<<endl;
cout<<minimoIndice + 1<<endl;



return 0;
}