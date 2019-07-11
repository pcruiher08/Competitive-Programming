#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iomanip>
#include <string>
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
    int n; 
    cin>>n; 
    string pal[n];
    FOR(i,0,n,1)cin>>pal[i];
    FOR(i,0,n,1)
    if(pal[i].length()<=10)
        cout<<pal[i]<<endl;
    else
        cout<<pal[i][0]<<pal[i].length()-2<<pal[i][pal[i].length()-1]<<endl;
}