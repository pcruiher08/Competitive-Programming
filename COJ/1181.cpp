#include <iostream>
#include <math.h>
using namespace std; 


double Fibonacci(int c){
  double phi = (1+sqrt(5))/2;
return floor((pow(phi, c)-pow((1-phi),c))/sqrt(5));
}
/*
1
3
-1
*/

int main() {
  int x =0; 
  while(cin>>x){
    
    if(x==-1)break;
  //x++;
  cout<<(long long)Fibonacci(x+2)-1<<" "<<(long long)Fibonacci(x+3)-1<<endl;
  x=0;
  }
}