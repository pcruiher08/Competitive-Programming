#include <iostream>
#include <math.h>

using namespace std;

int main() {
int n, a, b;
cin>>n>>a>>b;

while(n--){
  int p; 
  cin>>p;
  cout<<(p<=sqrt(pow(a,2)+pow(b,2))? "DA\n" : "NE\n");
}

}