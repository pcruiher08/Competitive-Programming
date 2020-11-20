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
#include <unordered_map>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define numeros make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;


bool sortFunction(int x, int y){
    return x>y;
}

int cuentaParesSumaPotenciaDeDos(vector<int> a){ 

    map<int, int> m; 
    for(int i=0; i<a.size(); i++){
      m[a[i]]++;
    }
  
    int cuenta = 0;
    //en int nomas te caben hasta 2^31
    for(int i=0; i<31; i++) { 
        int buscaPotencia = 1<<i; 
        for(int j = 0; j < a.size(); j++){ 
            if (m.find(buscaPotencia-a[j])==m.end()){
              continue;
            }else{
                cuenta+=m[buscaPotencia-a[j]]; 
            }
            if(buscaPotencia-a[j]==a[j]){
              cuenta++;
            } 
        } 
    } 
  
    return cuenta/2; 
} 

int main(){
sync;

vector<int> vec = {1,-1,2,3};
cout<<cuentaParesSumaPotenciaDeDos(vec);

return 0;
}