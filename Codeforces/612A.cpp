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
int main(){
    sync;
    int n, a, b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    double sLen = s.length();
    bool flag = false;
    int cuentaParticiones = 1;
        int cuentaB = 1, cuentaA = 1;
        //a*cuentaA + b*cuentaB = n ft-Roberto el salvador
        
        if(n%b == 0){
            cuentaA = n/b;
            cout << cuentaA <<endl;
            FOR(i,0,cuentaA*b,b)cout<<s.substr(i,b)<<endl;
            return 0;
        }

        if(n%a == 0){
            cuentaB = n/a;
            cout<<cuentaB<<endl;
            FOR(i,0,cuentaB*a,a) cout<<s.substr(i,a)<<endl;
            return 0;
        }

        while(cuentaB<=n/a){
          if((n-a*cuentaB)%b==0){
            flag=true;
            break;
          }
          cuentaB++;
      }

        if(flag){
            cuentaA = (n - a*cuentaB) / b;
            cout<<cuentaB+cuentaA<<endl;
            int cuentaParticiones = 0;
            while(cuentaParticiones<cuentaB*a){
              cout<<s.substr(cuentaParticiones,a)<<endl;
              cuentaParticiones+=a;
            }
            FOR(j,cuentaParticiones,cuentaParticiones+cuentaA*b,b)cout<<s.substr(j,b)<<endl;
            return 0;
        }
    cout<<-1<<endl;
}