/*
 #include <iostream>

int main(){
    unsigned int n;
    scanf("%i", &n);
    while(n--){
        unsigned a,b,suma=0;
        scanf("%i%i",&a,&b);
        for(int i=1; i<=a; i++){
            if(a%i==0&&i%b!=0){
                suma+=i;
            }
        }
        printf("%i\n", suma);
    }
}

// 5
 //20 2
 //10 1
 //20 5
 //7 5
 //20 40
 */
#include <iostream>
#include <vector>
//using namespace std;
int main(){
    int n;
    //cin>>n;
    scanf("%i", &n);
    int p=n;
    int suma=0;
    int e;
    int max =0;
    while(n--){
        int resultados[10];
        for(int i=0; i<10; i++){
            //cin>>e;
            scanf("%i", &e);
            resultados[i] = e;
        }
        int mayor =0;
        int menor =100;
        for(int i=0; i<10; i++){
        if(resultados[i]>mayor)
            mayor= resultados[i];
        if(resultados[i]<menor)
            menor = resultados[i];
        }
        //cout<<p-n<< " ";
        printf("%i", p-n);
        printf(" ");
        for(int i=0; i<10; i++){
            suma+=resultados[i];
        }
        suma=suma-mayor-menor;
        
        //cout<<suma<<endl;
        printf("%i\n", suma);
        if(suma>max) max = suma;
        suma=0;
    }
    //cout<<max;
    printf("%i", max);
}
/*
 3
 10 2 100 2 10 56 7 10 58 6
 5 3 4 2 1 1 2 3 4 5
 1 2 3 4 5 6 7 8 9 10
 */