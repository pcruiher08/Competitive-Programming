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

int t;cin>>t; 
while(t--){
    int n; cin>>n;
    int lista[n];
    for(int i = 0; i < n; i++){
        cin>>lista[i];
    }
    int alprincipio = 1, alfinal = 1;
    int iteradorInicio = 0;
    while(lista[iteradorInicio] == lista[iteradorInicio + 1] && iteradorInicio != n - 1){
        iteradorInicio++;
        alprincipio++;
    }

    int iteradorFinal = n - 1;
    while(lista[iteradorFinal] == lista[iteradorFinal - 1] && iteradorFinal != 1){
        iteradorFinal--;
        alfinal++;
    }

    if(lista[0] == lista[n - 1]){
        if(alprincipio == n){
            cout<<0<<endl;
        }else{
            cout<<n - alprincipio - alfinal<<endl;
        }
    }else{
        cout<<n - max(alprincipio, alfinal)<<endl;

    }



}
return 0;

}