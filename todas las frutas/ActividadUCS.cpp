#include <algorithm>
#include <math.h>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#define INF 0x3f3f3f3f
using namespace std;

int cuantosNodos = 10;

//un nodo
struct nodo{
   int id;
   int visitado;
   vector<pair<char, int> > camino;
};

//matriz de adyacencias para representar el grafo y evitar el problema de buscar el orden alfabetico en BFS y DFS, en UCS da igual porque la prioridad es por peso
//seria interesante implementarlo con lista de adyacencias, creo que el codigo quedaria un poco mas corto
int grafo[10][10] = {
    //A  B  C  D  E  F  G  H  I  J  
/*A*/{0, 0, 0, 0, 1, 2, 4, 0, 2, 0},
/*B*/{0, 0, 0, 0, 3, 0, 7, 8, 0, 6},
/*C*/{0, 0, 0, 0, 0, 6, 1, 0, 0, 0},
/*D*/{0, 0, 0, 0, 9, 0, 0, 0, 2, 0},
/*E*/{1, 3, 0, 9, 0, 0, 0, 0, 0, 5},
/*F*/{2, 0, 6, 0, 0, 0, 0, 0, 0, 0},
/*G*/{4, 7, 1, 0, 0, 0, 0, 0, 0, 0},
/*H*/{0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
/*I*/{2, 0, 0, 2, 0, 0, 0, 0, 0, 0},
/*J*/{0, 6, 0, 0, 5, 0, 0, 0, 0, 0},
};

//comparacion para pair<int, nodo> para la priority queue con pesos
class comparacion{    
    public:
        bool operator()(const pair<int, nodo>& n1, const pair<int,nodo>& n2){
            return n1.first > n2.first;
        }
};

//funcion de uniform cost search, va a regresar el nodo al que llegue, y el nodo contiene la lista del camino por el cual se alcanzo guardada en un vector de pares de caracteres y pesos
//seria interesante implementarlo con apuntadores de los nodos anteriores pero para esta implementacion no hizo falta
nodo ucs(nodo inicio, nodo fin){

    //priority queue para comparar por pesos, se usa la funcion que se declaro arriba
    priority_queue<pair<int, nodo>, vector<pair<int, nodo> >, comparacion > pqUCS;

    //para ver si ya se visito un nodo
    set<int> visitados;

    //para guardar los nodos que se expanden
    vector<nodo> expandidos;

    
    pqUCS.push(make_pair(0,inicio));

    while(!pqUCS.empty()){
        int peso = pqUCS.top().first;
        nodo actual = pqUCS.top().second;
        pqUCS.pop();

        //se revisa que no se haya visitado el actual
        if(visitados.count(actual.id) == 0){
            //se marca el actual en los visitados
            visitados.insert(actual.id);
            //aqui se guardan los nodos que se expandieron, pero no se imprimen en esta implementacion, puede que sea util para tareas futuras
            expandidos.push_back(actual);
        }

        //se revisa si se llego al objetivo
        if(actual.id == fin.id){
            return actual;
        }

        //se itera sobre los nodos
        for(int i = 0; i<cuantosNodos; i++){
            //se revisa que exista adyasencia y que no se haya visitado el nodo actual
            if(grafo[actual.id][i] && visitados.count(i) == 0){                
                //se hace un nodo nuevo y se actualiza con la informacion que necesita para entrar a la pq
                nodo nuevo;
                nuevo.id = i;
                nuevo.visitado = 0;
                nuevo.camino = actual.camino;
                nuevo.camino.push_back(make_pair(i+'A', peso + grafo[actual.id][i]));
                //se inserta el nodo nuevo en la queue con el peso correspondiente al camino
                pqUCS.push(make_pair(peso + grafo[actual.id][i], nuevo));
            }
        }
    }
    cout<<"No hay camino entre los nodos solicitados"<<endl;
    nodo vacio;
    return vacio;
}


int main(){

    nodo inicio;
    nodo fin;



    //para simplicidad de recorrido, las letras se usaran como numeros con la configuracion A = 0, B = 1, C = 2, ...
    
    //se resta el valor de ascii de A a las letras para obtener la configuracion propuesta
    char letraInicio = 'B';
    inicio.id = letraInicio-'A';
    inicio.camino = {make_pair(letraInicio,0)};
    char letraFin = 'D';
    fin.id = letraFin - 'A';


    cout << "UCS de "<<letraInicio<<" a "<<letraFin<<endl;
    nodo res = ucs(inicio, fin);
    for(int i = 0; i<res.camino.size(); i++){
        cout<<char(res.camino[i].first)<<"("<<res.camino[i].second<<")"<<(i<res.camino.size()-1?"->":"\n");
    }

    /*
    OUTPUT
    ---------------


    UCS de B a D
    B(0)->E(3)->A(4)->I(6)->D(8)

    
    
    */
}