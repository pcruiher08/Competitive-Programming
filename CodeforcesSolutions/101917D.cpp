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

struct gun{
    int cost;
    double ratio;
    double rateCost;
};

bool func(gun uno, gun dos){
    if(uno.ratio!=1.0&&dos.ratio!=1.0)
        return (uno.cost/(1.0-uno.ratio)<(dos.cost/(1-dos.ratio)));
    return dos.ratio==0;
}

int main() {
    sync;
    int n;
    long double w;
    cin>>n>>w;
    gun guns[n];
    FOR(i,0,n,1){
        cin>>guns[i].cost>>guns[i].ratio;
        guns[i].rateCost=guns[i].cost*guns[i].ratio;
    }
    sort(guns, guns+n, func);
    //for(int i=0; i<n; i++)
    //     cout<<guns[i].rateCost<<" ";
    //cout<<endl;
    long double res = 0;
    for(int i=0; i<n; i++){
        res+=guns[i].cost*w;
        w*=guns[i].ratio;
    }
    cout<<fixed<<setprecision(12)<<res;
}