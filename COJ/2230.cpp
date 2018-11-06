#include <iostream>
#include <algorithm>
using namespace std; 

int main() {
  int n; 
  cin>>n; 
  int vector1[n];
  int vector2[n];
  
  for(int i=0; i<n; i++)
  cin>>vector1[i];
  for(int i=0; i<n; i++)
  cin>>vector2[i];
  
  sort(vector1, vector1 + n);
  sort(vector2, vector2 + n);
  
  int producto = 0; 
  for(int i=0; i<n; i++)
  producto+=vector1[i]*vector2[n-i-1];
  
  cout<<producto;
  
}