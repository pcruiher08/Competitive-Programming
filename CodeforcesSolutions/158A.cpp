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
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){
    sync;
    int a,b;
    cin>>a>>b;
    int comp[a];
    int check,cnt=0;
    FOR(i,0,a,1)cin>>comp[i];
    int k = comp[b-1];
    FOR(i,0,a,1){
        //cout<<i<<" comp[i] "<<comp[i]<<", k: "<<k<<endl;
        if((comp[i]>=k)&&(comp[i]>0))
            cnt++;
    }
    cout<<cnt;
    return 0;
}