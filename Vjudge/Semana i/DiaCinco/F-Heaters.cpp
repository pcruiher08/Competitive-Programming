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
int n,r; 
cin>>n>>r;

int arr[n];
FOR(i,0,n,1)cin>>arr[i];
int inicia = 0;
int cuenta = 0;
while(inicia<n){
    int j=n-1;
    while(!(j<0)&&(j>=inicia-r+1)&&(!arr[j])||(j-r+1>inicia))j--;
    if(j==inicia-r||j==-1){
        cout << -1 << endl;
        return 0;
    }
    cuenta++;
    inicia = j + r;
}
cout<<cuenta<<endl;
return 0;

}
