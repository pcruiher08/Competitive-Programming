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

int gauss(int n){ return (n*(n+1)*0.5);}
int main(){
sync;
int nodos; cin>>nodos;
int edges; cin>>edges;

int matAdj[nodos][nodos];
//memset(matAdj,0,sizeof(matAdj));
FOR(i,0,nodos,1)FOR(j,0,nodos,1)matAdj[i][j]=0;

FOR(i,0,edges,1){
    int j,k; 
    cin>>j>>k;
    matAdj[j-1][k-1]++;
}

int matrizDeNodos[nodos][nodos];

//memset(matrizDeNodos,0,sizeof(matrizDeNodos));
FOR(i,0,nodos,1)FOR(j,0,nodos,1)matrizDeNodos[i][j]=0;

int piso = 0; 
int acumulador = 0;

while(piso<nodos){
    FOR(i,0,nodos,1){
        //cout<<matAdj[piso][i]<<" ";
        if(matAdj[piso][i]){
            FOR(j,0,nodos,1)
            if(matAdj[i][j])
            matrizDeNodos[piso][j]++;
        }
    }
    //cout<<endl;
    piso++;
}
/*
cout<<"----------------"<<endl;

for(int i= 0; i<nodos; i++){
    for(int j= 0; j<nodos; j++){
        cout<<matrizDeNodos[i][j]<<" ";
    }
    cout<<endl;
}
*/
FOR(i,1,nodos+1,1)FOR(j,1,nodos+1,1)if(i!=j)acumulador+=gauss(matrizDeNodos[i-1][j-1]-1);

cout<<acumulador<<endl;
return 0;
}