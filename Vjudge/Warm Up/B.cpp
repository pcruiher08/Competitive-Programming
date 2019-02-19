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

int main(){
sync;
int l, r; cin>>l>>r; 
int cuenta = 0; 
int pos = 0; 
int inicio; 
int arr[l]; FOR(i,0,l,1)cin>>arr[i];
/*
10 3
0 0 1 1 0 1 0 0 0 1
*/
while(pos<l){
    inicio = -1; //cada vez que vuelve a checar
    FOR(i,0,l,1)if(arr[i] && (i-r+1) <= pos && (i+r-1)>= pos) inicio = i;
    if(inicio == -1){cout<<"-1"<<endl; return 0;}
    cuenta++; 
    pos = inicio + r; 
}

cout<<cuenta<<endl;


return 0;
}