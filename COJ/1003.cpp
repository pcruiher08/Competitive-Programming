#include <iostream>
using namespace std; 

int main() {
  int n; 
  cin>>n; 

  while(n--){
    int a, b;
    cin>>b>>a; 

    int mat[b]; 
    int lec = 0; 

    for(int i=0; i<b; i++)
      mat[i] = 0; 

    for(int i=0; i<a; i++){
      for(int j=0; j<b; j++){
        cin>>lec;
        mat[j] += lec; 
      }
    }
  int max = mat[0];
  int maxi = 0;
  for(int i=0; i<b; i++)
    if(mat[i]>max){
      max = mat[i];
      maxi = i; 
    }
  cout<<maxi+1<<endl; 
  }
}