#include <iostream>
#include <math.h>
using namespace std;
int main() {
  string s; 
  int len;
  cin>>len;
  cin>>s;
  
  int cuenta0 = 0;
  int cuenta1 = 0;
  
  for(int i=0; i<len; i++){
    if(s[i]=='0'){
      cuenta0++;
    }
    if(s[i]=='1'){
      cuenta1++;
    }
  }
  
  while(cuenta1>1)
  cuenta1 = ceil(cuenta1/2); 
  
  if(cuenta1)
  cout<<1;
  while(cuenta0--)
  cout<<0;
}