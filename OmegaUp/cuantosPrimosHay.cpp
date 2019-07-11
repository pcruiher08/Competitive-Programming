#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int num,i,count,n;
    int contador = 0;
    
    cin >> n;
    for(num = 1;num<=n;num++){
         count = 0;
         for(i=2;i<=num/2;i++){
             if(num%i==0){
                 count++;
                 break;
             }
        }
       
         if(count==0 && num!= 1)
         contador = contador + 1;
              
    }
    if(contador == 0){
        cout<<"No existen numeros primos en la cantidad ingresada.";
        }else{
    cout<<contador;
    }
 
   return 0;
}
