#include <iostream>
using namespace std; 
int main(){
unsigned long long a, b, suma, i, u; 
cin>>a>>b; 
if(a>=b)u=a, i=b;
else u=b, i=a; 
//suma=((a+b-1)*(a+b)-(i)*(i+1))*0.5;
suma=u*(2*i-1);
cout<<suma;
}
