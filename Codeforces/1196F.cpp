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

void dfs(vector<int> &acumulador, int nodoActual, bool visitados[], int cuantosNodosHay, int *mat[], int sumaActual, bool realmenteVisitados[]){   
    FOR(i,0,cuantosNodosHay,1){
        realmenteVisitados[i+1] = true;
        //visitados[i+1] = true;
        //if(i>=cuantosNodosHay) visitados[i+1] = true;
        //FOR(k,0,cuantosNodosHay,1)cout<<visitados[k]<<",";
        //memset(visitados,0,sizeof(visitados));
        //FOR(k,0,i,1)visitados[k] = true;
        FOR(j,0,cuantosNodosHay,1){
            //visitados[i+1] = true;
            if(!visitados[j+1] && mat[i][j]!=0 && i!=j){
                //visitados[j+1] = true;
                
                if(!visitados[j+1]) sumaActual = 0;
                acumulador.pb(sumaActual+mat[i][j]);
                cout<<"nodo: " << i + 1 <<" a "<< j + 1 << " peso: " << mat[i][j] <<" acum: " << sumaActual + mat[i][j] <<endl;
                //cout<<"MARCANDO COMO VISITADO AL NODO: "<<j+1<<endl;
                visitados[j+1] = true;

                dfs(acumulador,j+1,visitados,cuantosNodosHay,mat,sumaActual+mat[i][j], realmenteVisitados);  
            }
        }
    }
}
/*
8 11 5
2 5 1
5 3 9
6 2 2
1 3 1
5 1 8
6 5 10
1 6 5
6 4 6
3 6 2
3 4 5
7 8 1

*/

int main(){
sync;
int n, m, k; 

cin>>n>>m>>k;

int* mat[n];
FOR(i,0,n,1){
    int* tmp = new int[n];
    FOR(j,0,n,1)tmp[j] = 0;
    mat[i] = tmp;
}

while(m--){
    int i, j; 
    int peso;
    cin>>i>>j>>peso;
    mat[i-1][j-1] = peso;
    mat[j-1][i-1] = peso;
}

bool visitados[n+1];
bool realmenteVisitados[n+1];
FOR(i,0,n,1)visitados[i] = 0;
int sumaActual = 0;

cout<<"......PRINT MATRIZ ACTUAL........"<<endl;
FOR(i,0,n,1){FOR(j,0,n,1){cout<<mat[i][j]<<" ";}cout<<endl;}


vector<int> acumulador;
//FOR(i,0,n,1){
    memset(realmenteVisitados,0,sizeof(realmenteVisitados));
    memset(visitados,0,sizeof(visitados));
    dfs(acumulador, 1, visitados, n, mat, sumaActual, realmenteVisitados);
//}
sort(acumulador.begin(), acumulador.end());
cout<<"james"<<endl;
//cout<<acumulador[k-1]<<endl;
return 0;
}