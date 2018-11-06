#include <iostream>
using namespace std;
int main() {
  int n, primero, ultimo;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  if(arr[0]%2==0||arr[n-1]%2==0||n%2==0){
    cout<<"No";
  }
  else
 cout<<"Yes";
}