#include <iostream>
#include <math.h>
using namespace std; 

long long factorial(int n){
   if (n==1 || n==0)
    return 1;
   else
    return n*factorial(n-1);
 }
 
int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
  
    int par; 
    cin>>par;
    
    long long r = factorial(par);
    cout<<"Case #"<<i+1<<": "<<r<<endl;
  }
    
  }
