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

int cuantosNodos = 10;

struct node{
   int id;
   int visitado;
};

int grafo[10][10] = {
    //A  B  C  D  E  F  G  H  I  J  
/*A*/{0, 0, 0, 0, 1, 1, 1, 0, 1, 0},
/*B*/{0, 0, 0, 0, 1, 0, 1, 1, 0, 1},
/*C*/{0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
/*D*/{0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
/*E*/{1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
/*F*/{1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
/*G*/{1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
/*H*/{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
/*I*/{1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
/*J*/{0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
};

void dfs(node inicio, node fin){
    node actual;
    stack<node> stackDFS;
    
    node vertices[cuantosNodos];

    for(int i = 0; i<cuantosNodos; i++){
        vertices[i].id = i;
        vertices[i].visitado = 0;
    }

    vertices[inicio.id].visitado = 1;

    stackDFS.push(inicio);
    while(!stackDFS.empty()){
        
        actual = stackDFS.top();
        stackDFS.pop();

        cout << char(actual.id+'A') << " ";

        if(actual.id == fin.id){
            return;
        }

        for(int i = 0; i<cuantosNodos; i++){
            if(grafo[i][actual.id]){
                if(vertices[i].visitado == 0){
                    vertices[i].visitado = 1;
                    stackDFS.push(vertices[i]);
                }
            }
        }
    }
}

void bfs(node inicio, node fin){
    node actual;
    queue<node> queueBFS;
    
    node vertices[cuantosNodos];

    for(int i = 0; i<cuantosNodos; i++){
        vertices[i].id = i;
        vertices[i].visitado = 0;
    }

    vertices[inicio.id].visitado = 1;

    queueBFS.push(inicio);
    while(!queueBFS.empty()){
        
        actual = queueBFS.front();
        queueBFS.pop();

        cout << char(actual.id+'A') << " ";

        if(actual.id == fin.id){
            return;
        }

        for(int i = 0; i<cuantosNodos; i++){
            if(grafo[i][actual.id]){
                if(vertices[i].visitado == 0){
                    vertices[i].visitado = 1;
                    queueBFS.push(vertices[i]);
                }
            }
        }
    }
}






int main(){
    sync;

    node inicio;
    node fin;

    char letraInicio = 'B';
    inicio.id = letraInicio-'A';
    char letraFin = 'F';
    fin.id = letraFin - 'A';

    //cout << "DFS de "<<letraInicio<<" a "<<letraFin<<endl;
    //dfs(inicio, fin);
    //cout << endl;
    cout << "BFS de "<<letraInicio<<" a "<<letraFin<<endl;
    bfs(inicio, fin);
}