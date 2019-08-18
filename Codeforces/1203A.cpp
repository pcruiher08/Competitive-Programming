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
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

bool isCounter(int arr[], int n){
    int maximo = arr[0];
    int maximoIndex = 0;
    FOR(i,1,n,1){
        if(arr[i]>maximo) maximo = arr[i], maximoIndex = i;
    }
    cout<<"maximoIndex: "<<maximoIndex<<endl;
    cout<<"maximo: "<<maximo<<endl;
    FOR(i,maximoIndex,n-1,1){
        if(arr[i%n]!=arr[(i+1)%n]+1){
            cout<<"salida en: "<<arr[i%n]<<"<"<<arr[(i+1)%n]<<endl;
            return false;
            }
    }
    return true;
}

bool isClock(int arr[], int n){
    int minimo = arr[0];
    int minimoIndex = 0;
    FOR(i,1,n,1){
        if(arr[i]<minimo) minimo = arr[i], minimoIndex = i;
    }
    cout<<"minimoIndex: "<<minimoIndex<<endl;
    cout<<"minimo: "<<minimo<<endl;
    FOR(i,minimoIndex,n-1,1){
        if(arr[(i+1)%n]-1!=arr[i%n]){
            cout<<"salida en: "<<arr[i%n]<<">"<<arr[(i+1)%n]<<endl;
            return false;
            }
    }
    return true;
}

int main(){
sync;
int n;
cin>>n; 
while(n--){
    int k; cin>>k;
    int arr[k];
    FOR(i,0,k,1)cin>>arr[i];
    if(isClock(arr,k)||isCounter(arr,k))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

return 0;
}