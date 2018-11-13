#include <iostream>
using namespace std;

int main() {
  double sum; 
  int n = 12;
  double num;
while(n--){
  cin>>num;
  sum+=num;
}
cout<<"$";
cout<<sum/12;
}