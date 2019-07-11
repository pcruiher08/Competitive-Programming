#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int main() {
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

  int n; 

  while(cin>>n){
  string lee; 
  cin>>lee; 
  reverse(lee.begin(),lee.end());

  for(int i=0; i<lee.length(); i++){
    cout<<alphabet[(alphabet.find(lee[i])+n)%(alphabet.size())];
  }
  cout<<endl;



  }
  
}