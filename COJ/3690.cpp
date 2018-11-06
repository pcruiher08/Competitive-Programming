#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

int main(){
    long long int r; 
    long long int n;

    double pi = 3.1415927;
    while(cin>>r>>n){
    if(n==0&&r==0)break;
    
    if(n>=100000){
      cout<<pi*r*r<<endl;
    }else{
    long double ladoIzq = n * 2*r*sin(pi/n)* 2*r*sin(pi/n)/4;
    long double ladoDer = 1.0/tan(360*pi/(n*180))-1.0/tan((180-360.0/n)*pi/180);
    cout<<setprecision(10)<<ladoDer*ladoIzq<<endl;
    }

    }
    

    
}
