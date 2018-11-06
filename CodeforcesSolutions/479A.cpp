#include <iostream>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;

  int max = a+b*c;
  if(max< a*(b+c)){
    max = a*(b+c);
  }

  if(max< (a+b)*c){
    max = (a+b)*c;
  }

  if(max< a*b*c){
    max = a*b*c;
  }

  if(max< a+b+c){
    max = a+b+c;
  }

 cout<<max; 
}