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
#include <climits>

#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
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
    int n,k; 
    cin>>n>>k;
    int aux = 0;
    int aux2 = INT_MIN;
    int arr[n];
    int dif[n-1];
    FOR(i,0,n,1){
        cin>>arr[i];
        if(i>0&&i<k)aux+=(arr[i]-arr[i-1]);
    }

    if(aux>aux2){
        aux2 = aux;
    }
    aux-=(arr[1]-arr[0]);
    //FOR(i,1,n-k,1){
    for(int i=1; i<n-k; i++, aux-=(arr[i]-arr[i-1])){
        aux+=(arr[i+k-1]-arr[i+k-2]);
        if(aux>aux2){
            aux2 = aux;
        }
        //aux-=(arr[i]-arr[i-1]);
    }
    cout<<aux2<<endl;

/*
6 4
2 1 3 2 6 2
*/

}