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

string s; 
int n,k; cin>>n>>k>>s;
int uno =0, dos = 0; 
int cuentaA = 0; 
int cuentaB = 0;
int i = 0;
int j = 0;
int respuesta = 0;

while(i<n){

    if(s[i]=='b') cuentaB++;
    if(s[i]=='a') cuentaA++;
    if(cuentaA<=k || cuentaB<=k){
        respuesta++;
        i++;
    }else{
        if(s[j] == 'a') cuentaA--;
        if(s[j] == 'b') cuentaB--;
        j++;
        i++;
    }


}
cout<<respuesta<<endl;

return 0;
}
