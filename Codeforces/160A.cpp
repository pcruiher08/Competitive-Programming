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
    int n; 
    cin>>n;
    int arr[n];
    int sum=0;
    FOR(i,0,n,1)cin>>arr[i],sum+=arr[i];
    sort(arr,arr+n);
    int meLasLlevo = 0, cuantasMeLlevo=0;
    ROF(i,0,n-1,1){
        meLasLlevo+=arr[i];
        //cout<<"moneda # "<<i<<" = "<<arr[i]<<endl;
        cuantasMeLlevo++;
        if(2*meLasLlevo>sum){
            cout<<cuantasMeLlevo<<endl;
            return 0;
        }
    }
}