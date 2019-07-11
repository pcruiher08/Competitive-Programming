#include <algorithm>
#include <iostream>
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)

int main(){
int arr[4];
FOR(i,0,4,1)std::cin>>arr[i];
std::sort(arr,arr+4);
FOR(i,0,4,1)std::cout<<arr[i]<<" ";
}