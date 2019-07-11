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

struct ninio{
    int arr[5];
    int promedioReal;
    int promedioReportado;
};

int average(ninio x){
    int sum = 0;
    FOR(i,0,5,1){
        sum+=x.arr[i];
    }
    return sum/5;
}

int main(){
sync;
int n; 
cin>>n;

ninio ninios[n];
FOR(i,0,n,1){
    FOR(j,0,5,1){
        cin>>ninios[i].arr[j];
        ninios[i].promedioReal = average(ninios[i]);
    }
    cin>>ninios[i].promedioReportado;
    if(ninios[i].promedioReportado!=ninios[i].promedioReal){
        cout<<i+1<<" "<<ninios[i].promedioReal<<endl;
    }

}

return 0;
}