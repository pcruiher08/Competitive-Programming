#include <iostream>
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

ll fastPow(ll a,ll b){
    ll ret = 1;
    while(b>0){
        if(b&1) ret = (ret*a);
        a=(a*a);
        b>>=1;
    }
    return ret;
}
///for the following implementation I use my competitive programming template with a little mods
int main(){
sync;

//given the size of the set
int n; cin>>n;
int givenSet[n];
//reading the set (just for testing)
FOR(i,0,n,1)cin>>givenSet[i];
int totalXor = 0; 
FOR(i,0,n,1)FOR(j,i,n,1)totalXor^=givenSet[j];
cout<<totalXor;
return 0;
}