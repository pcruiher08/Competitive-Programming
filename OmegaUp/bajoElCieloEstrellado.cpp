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
int bitMask[50001] = {0};
int stars[500001] = {0};
int main(){
sync;
int n; cin>>n; 
int count = 0;
while(n--){
    int x,y; cin>>x>>y;
    if(!bitMask[x]){
        count++;
        bitMask[x]++;
        stars[x]=y;
    }else if(stars[x]>y){
        stars[x]=y;
    }
}
cout<<count<<endl;
FOR(i,0,500001,1){
    if(stars[i]){
        cout<<i<<" "<<stars[i]<<endl;
    }
}
return 0;
}