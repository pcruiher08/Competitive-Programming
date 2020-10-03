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


ll rango(vector<long long> arr, int a, int b){
    return arr[b] - arr[a - 1];
}


int upperBound = 2 * 100000 + 5;
int main(){
sync;
int t; cin>>t;
while(t--){
    int n,k; cin>>n>>k;
    //int fenwick[upperBound];
    vector<long long> fenwick;
    fenwick.assign(10000,0);
    //map<int,int> fenwick;
    int maxLec;
    for(int i = 0; i < n; i++){
        int lec; cin>>lec;
        fenwick[lec]++;
        maxLec = max(lec,maxLec);
    }
    for(int i = 0; i < n; i++){int basura; cin>>basura;}
    for(int i = 1; i <= maxLec + 1; i++){
        fenwick[i]+=fenwick[i-1];
    }

    //print
    /*
    for(int i = 0; i<10; i++){
        cout<<fenwick[i]<<" ";
    }
    cout<<endl;
    */
    int a = 1;
    int b = a + k;
    int cuantosSeSalvan = 0;

    int maxB = -1;
    int primerPasada = 0;
    for(int i = 0; i<maxLec + 1; i++){
        if(rango(fenwick,a+i,b+i) > primerPasada){
            maxB = b + i;
            primerPasada = rango(fenwick,a+i,b+i);
        }
    }

    cuantosSeSalvan += primerPasada;

    int segundaPasada = 0;

    for(int i = 0; i<maxLec + 1; i++){
        if(rango(fenwick,a+i,b+i) > segundaPasada && b + i != maxB){
            segundaPasada = rango(fenwick,a+i,b+i);
        }
    }

    cuantosSeSalvan += segundaPasada;
    cout<<cuantosSeSalvan<<endl;


    /*
1
7 1
1 5 2 3 1 5 4
1 3 6 7 2 5 4
    */

}
return 0;
}