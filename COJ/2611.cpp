#include <math.h>
#include <iostream>
using namespace std;

int main(){
    int partidos, comprar, puntos=0;
    cin>>partidos>>comprar;
    int dif[partidos];
    int a, b;
    for(int i=0; i<partidos; i++){
        cin>>a>>b;
        dif[i]=a-b;//arreglo de diferencias
    }
    
    //ordena de menor a mayor
    int i, k;
    for(int j = 1; j<partidos; j++){
        k = dif[j];
        for(i=j-1; (i>=0) && (dif[i]<k); i--){
            dif[i+1] = dif[i];
        }
        dif[i+1]=k;
    }

    
    int diferencia;
    
    for(int e=0; e<partidos&&comprar>=0; e++){
        diferencia = dif[e];
        if(diferencia>0) puntos+=3;
        else if(diferencia==0&&comprar==0) puntos++;
        else if(diferencia==0&&comprar>0) puntos+=3, comprar--;
        else if(diferencia<0&&comprar-(abs(diferencia))>0){
            comprar=comprar-(abs(diferencia)+1);
            diferencia+=abs(diferencia+1);
            puntos+=3;
        }
        else if(diferencia<0&&comprar-(abs(diferencia))==0){
            comprar-=(abs(diferencia));
            diferencia+=abs(diferencia);
            puntos++;
        }
        
        //else if(comprar==0) puntos+=1;
    }
    
    cout<<puntos<<endl;
    
}