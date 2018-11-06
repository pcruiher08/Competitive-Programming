
#include <iostream>
#include <math.h>
using namespace std;
 

bool esCuadrado(int x){
    int s = sqrt(x);
    return (s*s == x);
}
 

bool isFibonacci(int n){
    return esCuadrado(5*n*n+4)||esCuadrado(5*n*n-4);
}

int main() {
  int n; 
  cin>>n; 
  while(n--){
    int x; 
    cin>>x; 
    if(isFibonacci(x)){
      cout<<"Harry wins"<<endl;
    }else{
      cout<<"Ron wins"<<endl;
    }
  }
}