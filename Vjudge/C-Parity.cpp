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
int n,b,k; 
cin>>b>>k;
bool even = false;
int a[k];
int num = 2;
FOR(i,0,k,1)cin>>a[i];

FOR(i,0,k-1,1){
    if(b&1){
        if(a[i]&1){
            num+=1;
            even = !even;
            // + impar * impar = + impar
        }else{
            //nada
            //+ impar * par = + par
        }
    }else{
        if(a[i]&1){
            // + par * impar =  + par
        }else{
            // + par * par = + par
        }
    }
}
if(a[k-1]&1)num++;

cout<<(num&1?"odd":"even")<<endl;

return 0;
}