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
#define MOD(x,n) ((x%n)+n)%n
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int main(){
sync;
int t; cin>>t;
while(t--){
    int n; char c; cin>>n>>c;
    int indexOfFirstG = -1;
    string semaforo = ""; cin>>semaforo;
    int distancias[n];
    memset(distancias,0,sizeof(distancias));
    int distancia = 0;
    

    FOR(i,0,n,1){
        if(semaforo[i] == 'g'){
            indexOfFirstG = i;
            break;
        }
    }

    int maximoDeC = -1;

    FOR(i,0,n,1){
        //cout<<semaforo[MOD(indexOfFirstG - i, n)];
        if(semaforo[MOD(indexOfFirstG - i, n)] == 'g'){
            distancia = 0;
        }
        distancias[MOD(indexOfFirstG - i, n)] = distancia++;

        if(semaforo[MOD(indexOfFirstG - i, n)] == c){
            maximoDeC = max(maximoDeC, distancias[MOD(indexOfFirstG - i, n)]);
        }
        
    }//cout<<endl;
    //cout<<"RES> ";
    cout<<maximoDeC<<endl;

}

return 0;
}