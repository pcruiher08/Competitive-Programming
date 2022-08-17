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

int arbol(int a, int nActual, int n, int b){
    if(n-1 > nActual){
        for(int i = 0; i < 10; i++){
            int nuevoNodo = a * 10 + i;
            if(nuevoNodo % b == 0){
                return arbol(a*10 + i, nActual + 1, n, b);
            }
        }
    }else{
        for(int i = 0; i < 10; i++){
            int nuevoNodo = a * 10 + i;
            if(nuevoNodo % b == 0){
                return nuevoNodo;
            }
        }
    }
    return -1;
}

int main(){
sync;

int a,b,n;
cin>>a>>b>>n;

cout<<arbol(a,0,n,b);


return 0;

}