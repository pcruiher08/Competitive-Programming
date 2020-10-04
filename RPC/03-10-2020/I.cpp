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
int arr[n];
FOR(i,0,n,1)cin>>arr[i];

map<int,int> m1;
map<int,int> m2;

FOR(i,0,n,1){
    m2[arr[i]] = i;
    if(m1.find(arr[i])==m1.end()){
        m1[arr[i]] = i;
    }
}
vi acomodos = {-1}; 
int maxi = 0;

FOR(i,0,n,1){
    maxi = max(maxi, m2.find(arr[i])->second);
    if(maxi == i){
        //busca acomodos en los minimos posibles
        acomodos.pb(i);
    }
}

vi minimos;

FOR(i,0,acomodos.size(),1){
    minimos.pb(INF);
}

minimos[0] = 0;
int newMax = 0;
FOR(i,1,minimos.size(),1){

    set<int> rolas;
    FOR(j,acomodos[i-1]+1,acomodos[i]+1,1)rolas.insert(arr[j]);

    while(!rolas.empty()){
        int cancion = *--rolas.end();
        rolas.erase(--rolas.end());
		int izq = 0, der = minimos.size()-1;
		while(izq<der){
            int num = izq + der + 1;
			if(minimos[num>>1] >= cancion) der = (num>>1)-1;
            else izq = num>>1;
		}
        newMax = max(newMax, izq+1);
        minimos[izq+1] = min(minimos[izq+1], cancion);
    }
}
cout<<m2.size() - newMax<<endl;
return 0;
}