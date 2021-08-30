#include <algorithm>
#include <math.h>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>

#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int cuantosNodos = 10;

struct nodo{
   int id;
   int visitado;
};


//lista de adyacencias para representar el grafo y evitar el problema de buscar el orden alfabetico
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
/*J*/{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
};

void dfs(nodo inicio, nodo fin){
    nodo actual;
    stack<nodo> stackDFS;
    
    nodo vertices[cuantosNodos];

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



int main(){
    sync;

    nodo inicio;
    nodo fin;

    char letraInicio = 'H';
    inicio.id = letraInicio-'A';
    char letraFin = 'I';
    fin.id = letraFin - 'A';

    cout << "DFS de "<<letraInicio<<" a "<<letraFin<<endl;
    dfs(inicio, fin);

    /*
    OUTPUT
    ---------------

    DFS de H a I
    H B J G C F A I

    
    
    */
}

}