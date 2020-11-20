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

struct caja{
    int id; int num; 
};

bool fun(caja a, caja b){
    return a.num < b.num;
}

int minMoves(int arr[], int n){
    int expectedItem = 1;
    FOR(i,0,n,1){
        if(arr[i] == expectedItem) 
            expectedItem++; 
    } 
  
    return n-expectedItem+1; 
} 

int main(){
sync;
int n; cin>>n; 
int orig[n];
caja cajas[n];

FOR(i,0,n,1){
    int lec; cin>>lec; 
    caja aux; aux.id = 0; 
    aux.num = lec; 
    cajas[i] = aux; 
    orig[i] = lec;
}

sort(cajas, cajas+n, fun);
map<int, int> m; 
FOR(i,0,n,1){

    m[cajas[i].num] = i+1;
}

FOR(i,0,n,1){
    
    orig[i] = m[orig[i]];
}
cout<<minMoves(orig, n)<<endl;



return 0;
}