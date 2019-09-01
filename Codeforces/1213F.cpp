#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
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
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

//int matPeque[200001];

void dfs(int nodoActual, bool visitados[], int cuantosNodosHay, int &cuantosCaminos, int mayor, int *mat[], int *caminos[]){   
    FOR(i,0,cuantosNodosHay,1){
        // cout<<"dfs #"<<i<<endl;
        if (caminos[nodoActual][i] > 0)continue;
        if(mat[nodoActual][i] <= mayor && mat[nodoActual][i]){
            visitados[i]=true;
            cuantosCaminos++;
            caminos[nodoActual][i] = cuantosCaminos;
            caminos[i][nodoActual] = cuantosCaminos;
            dfs(i,visitados,cuantosNodosHay,cuantosCaminos,mayor, mat, caminos);
        }
    }
}

int main(){
sync;
int nodos; int queries; 
cin>>nodos>>queries;
int *mat[nodos];
int *caminos[nodos];
// cout<<"nodos: "<<nodos<<endl;
// cout << "xdd"<<endl;

for (int i = 0; i < nodos;i++) {
    // cout << "xd"<<endl;
    int *aux = new int[nodos]; 
    int *caux = new int[nodos]; 
    FOR(j,0,nodos,1) {
        aux[j] = 0;
        caux[j] = 0;
    }
    mat[i] = aux;
    caminos[i] = caux;
}

// for (int i = 0; i < nodos; i++){for (int j = 0;j < nodos; j++){ cout << mat[i][j] << " ";}cout<<endl;}

FOR(i,0,nodos-1,1){
        // cout<<"i: "<<i<<endl;
        int x,y;
        cin>>x>>y;
        cin>>mat[x-1][y-1];
        // cout<<"no me he muerto en: y="<<y<<" x="<<x<<endl;
        mat[y-1][x-1] = mat[x-1][y-1];
        // cout<<y<<" "<<x<<endl;
        // if(i==nodos-2)cout<<"ya me voy"<<endl;
}

// cout << "hola"<<endl;
while(queries--){
    // cout << "Xd"<<endl;
    
    int query; cin>>query;
    int cuantosCaminos = 0;
    FOR(i,0,nodos,1){
        bool visitados[nodos+1];
        memset(visitados,false,sizeof(visitados));
        dfs(i,visitados,nodos,cuantosCaminos,query, mat, caminos);
        }
        int c = 0;
    // cout<<cuantosCaminos<<endl;
    for (int i = 0; i < nodos; i++) {
        for (int j = i; j < nodos; j++) {
            if (caminos[i][j] <= query)c++;
        }
    }
    cout << c << endl;
}
return 0;
}