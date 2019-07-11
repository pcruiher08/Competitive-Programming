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
int t; cin>>t;
int p,s,n;
stack<int> uno, dos;
while(t--){
    cin>>p>>s>>n;
    if(p==1){
        if(s==1){
            uno.push(n);
        }else{
            dos.push(n);
        }
    }else{
        int aux = n;
        if(s==1){
            while(uno.size()&&aux--){
                dos.push(uno.top());
                uno.pop();
            }
        }else{
            while(dos.size()&&aux--){
                uno.push(dos.top());
                dos.pop();
            }
        }
    }
}
while(uno.size()){
    cout<<uno.top()<<" ";
    uno.pop();
}
cout<<endl;
while(dos.size()){
    cout<<dos.top()<<" ";
    dos.pop();
}

return 0;
}