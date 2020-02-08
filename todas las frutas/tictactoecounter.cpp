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

int cuentaGanes = 0;


void print(vector<vector<int> > board){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<board[i][j];
        }cout<<endl;
    }

    cout<<"-------"<<endl;
}

//aqui se valida si alguna ficha es ganadora
bool validarGane(vector<vector<int> >board, int fichaJugada){
    for(int i=0; i<3; i++)
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]==fichaJugada&&fichaJugada==1){
            return true;
        }
    for(int i=0; i<3; i++)
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]==fichaJugada&&fichaJugada==1){
            return true;
        }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]==fichaJugada&&fichaJugada==1){
        return true;
    }
      
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]==fichaJugada&&fichaJugada==1){
        return true;
    }
    return false;
}


bool isValid(vector<vector<int> >board) { 
    int cuantasX=0, cuantasO=0; 

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cuantasX+=(board[i][j]==1); 
            cuantasO+=(board[i][j]==2); 
        }
    }
  
    if(cuantasX==cuantasO || cuantasX==cuantasO+1){ 
        if(validarGane(board, 2)){
            if(validarGane(board, 1)) 
                return false; 
            return (cuantasX == cuantasO); 
        } 
        if(validarGane(board, 1) && cuantasX != cuantasO + 1) 
        return false;  
  
        return true; 
    } 
    return false; 
} 




int main(){
sync;
int fichaJugada = 1;

int turno = 1;
int profundidad = 0;

vector<vector<int> > tablero; 
vector<vector<int > > tableroDePrueba;
/*
para este contador de tableros ganadores de la ficha x solo se considera
que el tablero tenga una combinacion valida, posible, y ganadora para la
ficha x. No se considera el orden en el que se colocan las fichas.
*/

//0 para vacio
//1 para x
//2 para o
for(int i=0; i<3; i++){
    vector<int> v; 
    v.push_back(0);
    tablero.push_back(v);
    tableroDePrueba.push_back(v);
    for(int j=0; j<3; j++){
        tablero[i].push_back(0);
        tableroDePrueba[i].push_back(0);
    }
}

//3^9 = 19683 diferentes estados del tablero

for(int i = 0; i < 19683; ++i){
    int c = i;


    for(int j = 0; j<3; j++){
        for(int k = 0; k<3; k++){
            //se simula el estado del tablero
            tableroDePrueba[j][k] = c%3;
            c/=3;
        }
        //se valida que sea un tablero nuevo y valido
        if(tableroDePrueba!=tablero&&isValid(tableroDePrueba)){
            tablero = tableroDePrueba;
            //solo se cuentan los ganes de la ficha x
            cuentaGanes+=validarGane(tablero,1);
        }
     
    }

}

cout<<cuentaGanes;



return 0;
}