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

//or not
int i = 0;
void aPostOrden(int pre[],int l,int r, int post[]){
FOR(j,l+1,r+1,1){ 
    if(pre[j]>pre[l])break;
    aPostOrden(pre,l+1,j-1,post);
    aPostOrden(pre,j,r,post);
    post[i++] = pre[l];
}
    return;
}

int main(){
sync;
int n; cin>>n;
int pre[n];
FOR(i,0,n,1) cin>>pre[i];
int post[n];
memset(post,0,sizeof(post));
aPostOrden(pre,n-1,n,post);
FOR(i,0,n,1)cout<<post[i]<<" ";
return 0;
}