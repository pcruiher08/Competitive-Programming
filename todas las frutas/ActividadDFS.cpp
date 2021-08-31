#include <algorithm>
#include <math.h>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>

#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int cuantosNodos = 10;

//un nodo
struct nodo{
   int id;
   int visitado;
};

//matriz de adyacencias para representar el grafo y evitar el problema de buscar el orden alfabetico
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

//en este vector se va a guardar el camino que se vaya encontrando
vector<char> camino;

//funcion de breadth first search, regresa true si se encontro un camino de inicio a fin
bool dfs(nodo inicio, nodo fin){
    nodo actual;

    //stack para el DFS, esta es la unica diferencia con la implementacion de BFS (y el acceso con top en vez de front)
    stack<nodo> stackDFS;

    //este arreglo se usara para recorrer la matriz de adyacencias en orden
    nodo vertices[cuantosNodos];

    for(int i = 0; i<cuantosNodos; i++){
        vertices[i].id = i;
        vertices[i].visitado = 0;
    }

    vertices[inicio.id].visitado = 1;

    stackDFS.push(inicio);
    
    //mientras la queue no se quede vacia, se sigue recorriendo
    while(!stackDFS.empty()){
        
        actual = stackDFS.top();
        stackDFS.pop();
        //se va creando el camino
        //se suma el valor de ascii de A para regresar la configuracion a caracteres
        camino.push_back(actual.id + 'A');

        //si se encontro camino, regresa true
        if(actual.id == fin.id){
            return true;
        }

        //se recorren todas los numeros (configuracion de letras)
        for(int i = 0; i<cuantosNodos; i++){
            //se revisa que haya adyacencia y que no se haya visitado antes
            if(grafo[i][actual.id] && vertices[i].visitado == 0){
                    //se marca como visitado y se hace insercion a la queue
                    vertices[i].visitado = 1;
                    stackDFS.push(vertices[i]);
            }
        }
    }

    //si no se encuentra camino, regresa false
    return false;
}


int main(){
    sync;

    nodo inicio;
    nodo fin;

    //para simplicidad de recorrido, las letras se usaran como numeros con la configuracion A = 0, B = 1, C = 2, ...
    
    //se resta el valor de ascii de A a las letras para obtener la configuracion propuesta

    char letraInicio = 'H';
    inicio.id = letraInicio-'A';
    char letraFin = 'I';
    fin.id = letraFin - 'A';

    cout << "DFS de "<<letraInicio<<" a "<<letraFin<<endl;    
    
    //si se encontro camino, se imprime
    if(dfs(inicio, fin)){
        for(int i = 0; i < camino.size(); i++){
            cout<<camino[i]<<(i < camino.size() - 1 ? "->" : "\n");
        }
    }else{
        cout<<"No hay camino entre los nodos solicitados"<<endl;
    }



    /*
    OUTPUT
    ---------------

    DFS de H a I
    H->B->J->G->C->F->A->I
    
    */
}