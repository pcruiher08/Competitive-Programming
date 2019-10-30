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
int n; cin>>n; 
vector<string>s;
vector<int> vol;
vol.pb(0);
string a = "";
string lee;
cin.ignore();
getline(cin,lee);
int mayor = 0;
int cuentaMayus = 0;
FOR(i,0,n,1){
    char c; 
    c = lee[i];
    if(c==' '){
        
        mayor = max(mayor,cuentaMayus);
        //cout<<"mayor: " <<mayor<<endl;
        cuentaMayus = 0;

    }else{
        if(lee[i]>='A'&&lee[i]<='Z'){
          //  cout<<"sume"<<endl;
            cuentaMayus++;
        }
    }

}
cout<<max(mayor,cuentaMayus)<<endl;

return 0;
}