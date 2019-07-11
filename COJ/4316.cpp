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

void fastscan(int &x){
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-'){
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}

int main(){
sync;
int n, s;
while(cin>>n>>s){
    int arr[n];
    map<int, int> m;
    bool found = false;
    memset(arr,0,sizeof(arr));
    FOR(i,0,n,1){int aux; cin>>aux; if(i>0)arr[i] = (arr[i-1] + aux); else arr[i] = aux;}

    FORb(i,0,n,1,!found){
        if(arr[i]==s){
            found = true;
        }else{
            m.insert(make_pair(arr[i]+s,i+1));
        }
        if(!found){ 
            if(m.find(arr[i]) != m.end()){
                found = true;
                cout << (int)m.find(arr[i])->second + 1 <<" " << i+1<<endl;
            }
        }else{
            cout<<1<<" "<<i+1<<endl;
        }

    }
    if(!found)cout<<-1<<endl;

}
return 0;
}