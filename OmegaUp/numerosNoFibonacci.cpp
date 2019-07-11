#include<iostream>
using namespace std;
int main(){
 int n,a,b,c,d;
 a=0;
 b=1;
 c=0;
 cin>>n;
 while(c<=n){
  c=a+b;
  a=b;
  b=c;
  d=a+b;
  for(int x=c+1;x<d;x++){
   if(x<n)
    cout<<x<<" ";
   else
    break;
  }
 }
}