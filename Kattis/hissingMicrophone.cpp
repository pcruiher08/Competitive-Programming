#include <iostream>
using namespace std; 

int main() {

  string p; 
  cin>>p; 

  int hissCount = 0; 

  for(int i=0; i<p.length()-1; i++){
    if(p[i]=='s'&&p[i+1]=='s'){
      hissCount++;
    }
  }
  cout<<(hissCount>0?"hiss":"no hiss");
}