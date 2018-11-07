
#include <iostream>
using namespace std; 
int main()
{
int n; 
int v;
int elBueno=0;
int b;
cin>>n;
cin>>v;
cin>>b;
if(n<v){
    elBueno=v;
    }
     else{
         elBueno=n;
  }
  if(elBueno<b){
      elBueno=b;
      }else{
          elBueno=elBueno;
          }
          cout<<elBueno;
}