#include <iostream>
#include <math.h>

using namespace std;

int main(){

int n,m,k; cin>>n>>m>>k;
int pizzas = 0; 
pizzas += k; 
int paraPuebla = k; 

pizzas += ceil(m/2.0);
if(m%2 != 0){
    paraPuebla += 2;
}

n-= paraPuebla; 
if(n>0){
    pizzas += ceil(n/4.0);
}

cout<<pizzas<<endl;
return 0;
}