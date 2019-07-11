#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
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
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int main(){
sync;

int n,k; 
int aux = 0;
int cuenta = 0;
cin>>n>>k; 
string s; cin>>s;
string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
if(k==2){

    FOR(i,0,n,1){
        if(s[i]==('A' + (i%2==1))){
            cuenta++;
        }
    }

    aux = min(n-cuenta,cuenta);
    FOR(i,0,n,1){
        bool valida = (cuenta == aux);
        s[i]='A'+(((cuenta==aux)+i)%2==1);
    }
 
}else{
    FOR(i,0,n,1){
        if(s[i]==s[i+1]){
            aux++;
            char letraAux; 
            letraAux = letras[0];
            int cuentaLetras = 0;
            while(letraAux==s[i]||letraAux==s[i+2]){
                
                cuentaLetras++;
                letraAux = letras[cuentaLetras%26];
               
            }
            s[i+1] = letraAux;

        }
    }
}
cout<<aux<<endl<<s<<endl;

return 0;
}