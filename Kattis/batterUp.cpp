#include <iostream>
#include <iomanip>
using namespace std; 

int main() {
  int a; 
  cin>>a;
  double suma=0; 
  double elementos=0; 
  double lectura; 
  double promedio; 
  while(a--){
    cin>>lectura; 
    if(lectura>-1){
      suma+=lectura; 
      elementos++;
    }
  }
  
  promedio = suma/elementos; 
  cout<<fixed<<setprecision(18)<<promedio;

}