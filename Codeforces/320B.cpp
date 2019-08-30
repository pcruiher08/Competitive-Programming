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

struct nodo {
    int id; 
    pair<int,int> nums;
};

bool isCompatible(nodo a, nodo b){
    return ((b.nums.first<a.nums.first && a.nums.first < b.nums.second) || (b.nums.first<a.nums.second && a.nums.second < b.nums.second));
}

void dfs(vector< vector<int> > grafo, bool visitados[], int origen, int destino, bool &encontrado){
    FOR(i,0,grafo[origen].size(),1){
        if(!visitados[grafo[origen][i]]){
            visitados[grafo[origen][i]] = true;
            if(grafo[origen][i] == destino){encontrado = true; return;}
            dfs(grafo,visitados,grafo[origen][i],destino,encontrado);
        }
    }
    return;
}

int main(){
sync;
vector <nodo> vectorDeNodos;
int queries; cin>>queries; 
vector< vector<int> > grafo(queries);
int contadorDeIDs = 0;
FOR(q,0,queries,1){
    int tipo; cin>>tipo; 
    if(tipo == 1){
        //metemos
        int a, b; 
        cin>>a>>b;
        nodo aux; 
        aux.id = contadorDeIDs; 
        contadorDeIDs++;
        aux.nums.first = a; 
        aux.nums.second = b;
        vectorDeNodos.pb(aux);

        FOR(i,0,vectorDeNodos.size()-1,1){
            if(isCompatible(vectorDeNodos[i],aux)){
                grafo[vectorDeNodos[i].id].pb(aux.id);
            }
            if(isCompatible(aux,vectorDeNodos[i])){
                grafo[aux.id].pb(vectorDeNodos[i].id);
            }
        }
    }else{//tipo == 2
        //preguntamos
        bool visitados[100];
        int a,b; cin>>a>>b;
        bool encontrado = false;
        memset(visitados,false,sizeof(visitados));
        dfs(grafo,visitados,a-1,b-1,encontrado);
        cout<<(encontrado?"YES":"NO")<<endl;

    }
}

/*
3
1 1 5
1 5 11
1 2 9


*/
/*

FOR(i,0,contadorDeIDs,1){
    cout<<" ("<<vectorDeNodos[i].nums.first<<" , "<<vectorDeNodos[i].nums.second<<") | ";
    FOR(j,0,grafo[i].size(),1){
        cout<<" ("<<vectorDeNodos[grafo[i][j]].nums.first<<" , "<<vectorDeNodos[grafo[i][j]].nums.second<<") ";
    }cout<<endl;
}
*/
return 0;
}