#include <iostream>
#include <stdio.h>
using namespace std; 





int main() {
  int n; 
  int a; 
  int b; 
  
  scanf("%d",&n);
  while(n--){
    scanf("%d",&a);
    scanf("%d",&b);
    //cin>>a; 
    //cin>>b; 
    if(a==b){
      printf("2\n");
      //cout<<2<<endl;
    }else{printf("1\n");}
  }
 
}