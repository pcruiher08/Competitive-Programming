#include <iostream>

using namespace std;

long long juguetes(long long n, long long k){
   if(k<=n){
    return (k-1)/2;
   }else if(k>n&&k<2*n){
    return (2*n-k+1)/2;
   }else{ 
    return 0;
   }
}
    
int main() {
  long long n, k, res; 
  cin>>n>>k;
   cout<<juguetes(n,k);
}