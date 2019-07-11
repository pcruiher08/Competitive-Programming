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
#include <deque>
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
void showdq(deque <int> g) 
{ 
    deque <int> :: iterator it; 
    for (it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
int main(){
sync;

deque<int> d;
int n, k; cin>>n>>k; 
int x; 
while(n--){cin>>x; d.push_back(x);}

    int aux, cuenta = 0;


    FOR(i,0,n,1){cin >> aux;d.push_back(aux);}
    while(!d.empty()){
        int cuantosLadosVan = 0;
        if (d.front() <= k) {
            d.pop_front();
            cuenta++;
        }else{
            cuantosLadosVan++;
        }
        if(d.empty())break;
        if(d.back()<=k) {
            d.pop_back();
            cuenta++;
        }else{
            cuantosLadosVan++;
        }
        if(cuantosLadosVan == 2)break;
    }
    cout << cuenta << endl;
}

