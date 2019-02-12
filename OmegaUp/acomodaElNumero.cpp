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

struct num{
    int n; 
    int pos;
};
/*
bool func(num a, num b){
    return a.n < b.n;
}
*/
int main(){
sync;
int n; cin>>n;
num arr[n];
int x;
FOR(i,0,n,1)cin>>x, arr[i].n = x, arr[i].pos = i;

sort(arr,arr+n,func);

FOR(i,0,n,1)if(arr[i].pos==0){cout<<i<<endl;return 0;}


return 0;
}