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

int m, o, p; 

int color(int x, int y){
    //par par||impar impar
    if(m%2==0&&o%2==0||m%2==1&&o%2==1){
        cout<<(x%2==0&&y%2==0||x%2==1&&y%2==1?p:(p==0?1:0))<<endl;
    }
    //par impar||impar par
    if(m%2==0&&o%2==1||m%2==1&&o%2==0){
        cout<<(x%2==0&&y%2==1||x%2==1&&y%2==0?p:(p==0?1:0))<<endl;
    }
}

int main(){
sync;


cin>>m>>o>>p;

int n; 
cin>>n; 
int x, y;
while(n--){
    cin>>x>>y;
    color(x,y);
}

return 0;
}