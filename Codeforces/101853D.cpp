#include <iostream>
using namespace std;

int main() {
  int casos = 0; 
  cin>>casos;
  while(casos--){
    int globos = 0; 
    cin>>globos;

    int colores = 0; 
    int aux = 0; 
    
    while(globos--){
      cin>>aux; 
      if(aux!=0){
        colores++;
      }
    }
    cout<<colores<<endl;

  }
}