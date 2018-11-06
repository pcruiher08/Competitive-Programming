#include <iostream>
using namespace std;

int GCD(int b, int a){
    while (a!=0) {
        int c=b%a;
        b=a;
        a=c;
    }
    return b;
}

int main() {
  int x; 
  cin>>x; 
    int cp = 0;
  for(int i=1; i<x; i++){
    if(GCD(x,i)==1)cp++;
  }
  cout<<cp;
}