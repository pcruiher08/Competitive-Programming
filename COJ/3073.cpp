#include <iostream>

using namespace std; 

int main(){
  int n; 
  cin>>n;
  while(n--){
    string p; 
    cin>>p; 
    
    if(p.size()>10){
      cout<<p[0]<<p.size()-2<<p[p.size()-1]<<endl;
    }else{
      cout<<p<<endl;
    }
  }
  
}



/*
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis
*/