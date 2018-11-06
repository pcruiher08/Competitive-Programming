#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=2; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define pb push_back
#define mod 1000000009
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>

using namespace std;
//super bruteforceado
int main() {
    sync;
    string n;
    cin >> n;
    ll primero=0, segundo=0, tercero=0;
    unsigned long len = n.length();
    
    FOR(i,0,len,1){
        primero = n[i]-'0';
        if(primero%8==0){
            cout<<"YES"<<endl;
            cout<<primero<<endl;
            return 0;
        }
    }
    
    FOR(i,0,len,1)
        FOR(j,i+1,len,1){
            segundo = (10*(n[i]-'0')+(n[j]-'0'));
            if(segundo%8==0){
                cout<<"YES"<<endl;
                cout<<segundo;
                return 0;
            }
        }
    
    FOR(i,0,len,1)
        FOR(j,i+1,len,1)
            FOR(k,j+1,len,1){
                tercero = (100*(n[i]-'0')+10*(n[j]-'0')+(n[k]-'0'));
                if(tercero%8==0){
                    cout<<"YES"<<endl;
                    cout<<tercero<<endl;
                    return 0;
                }
            }
    
    
    cout<<"NO"<<endl;
}