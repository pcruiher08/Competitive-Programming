#include <iostream>

using namespace std;
int main() {
  int n; 
  cin>>n;
  n--;
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int suma = a+b+c+d;
  int rank = 1; 
  while(n--){
    cin>>a>>b>>c>>d;
    int nuevaSuma = a+b+c+d;
    if (nuevaSuma>suma){
      rank++;
    }
  }
  cout<<rank;
}