#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=2; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

/*
 7 1
 1 0 1 1 0 0 0
 1 2
 1 3
 2 4
 2 5
 3 6
 3 7
 */

vector <int> tree[1000000];
int restaurantes = 0;
bool yaVisite[1000000];
int esValido;
void dfs(int cuantosVan, int anterior, int catLocation[], int vertices, int cats){
    yaVisite[anterior]=true;
    int cuantosGatos = 0;
    if((cuantosVan)>cats) return;
    esValido = 1;
    for(int i=0; i<tree[anterior].size(); i++){
        if(!yaVisite[tree[anterior][i]]){
            if(catLocation[tree[anterior][i]]==1) cuantosGatos=cuantosVan+1;
            if(catLocation[tree[anterior][i]]==0) cuantosGatos=0;
            dfs(cuantosGatos, tree[anterior][i], catLocation, vertices, cats);
            esValido=0;
        }
    }
    restaurantes+=esValido;
}


int main(){
    sync;
    int vertices,cats;
    cin>>vertices>>cats;
    int catLocation[vertices+1];
    int x,y;
    FOR(i,0,vertices,1) cin>>catLocation[i+1];
    
    for(int i=0; i<vertices-1; i++){
        cin>>x>>y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    int cantidadDeGatos = catLocation[1];//en la casa
    dfs(cantidadDeGatos,1,catLocation,vertices,cats);
    cout<<restaurantes;
    return 0;
}