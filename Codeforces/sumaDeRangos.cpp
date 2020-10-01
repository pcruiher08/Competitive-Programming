#include <iostream>

using namespace std;

int main(){
    //te dan un arreglo de enteros cualquiera
    int arregloDeEnteros[10] = {2,43,5,23,6,23,678,43,1,8};

    //te dan queries [a,b] para calcular la suma del indice a al indice b
    int a = 3;
    int b = 7;

    //por ejemplo en este caso hay que sumar los elementos desde el indice a hasta b inclusivos
    //23 + 6 + 23 + 678 + 43 = 773

    //esta suma normalmente la harías lineal si solo te dan un rango [a,b], pero en este caso hay que pensar en algo mas inteligente para hacer muchas sumas de rangos

    //aqui es donde entra el fenwick tree

    //supongamos que arregloDeEnteros no est'a vacio

    //vamos a modificar/armar un arreglo nuevo basandonos en nuestro arreglo anterior para que nos de mas informacion
    int fenwick[10] = {arregloDeEnteros[0],0,0,0,0,0,0,0,0,0};

    //guardemos en el indice i del arreglo fenwick la suma del rango [0,i]

    for(int i = 1; i < 10; i++){
        fenwick[i] = fenwick[i-1] + arregloDeEnteros[i];
    }

    //tambien se puede hacer sin memoria adicional utilizando el arreglo original

    //como ya calculamos las sumas de rangos de [0,i] y las guardamos en fenwick[i], podemos calcular cualquier rango [a,b] restando dos rangos
    //de forma general queda [a,b]-[0,a-1] = [a,b]
    //esto se traduce a accesos en tiempo constante al arreglo fenwick 
    //rango = fenwick[b] - fenwick[a-1]

    //la unica excepcion a esta regla sería cuiando te piden un rango [0,b], en este caso solo necesitas hacer un acceso al arreglo
    //rango = fenwick[b]


    return 0;
}