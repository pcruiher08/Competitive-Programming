#include <iostream>
using namespace std;
int main() {
  int x, n, suma = 0, p; 
  cin>>x>>n;
  for(int i=0; i<n; i++){
    cin>>p;
    suma+=p;
  }
  cout<<(n+1)*x-suma;
}