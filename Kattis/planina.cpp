#include <iostream>
using namespace std; 

int main() {
  int n; 
  cin>>n; 
  int conteo=1;
  for(int i=0; i<n; i++){
    conteo*=2;
  }
  cout<<(conteo+1)*(conteo+1);
}