#include <iostream>
using namespace std; 

int main() {
  int a,b,c; 
  int x;
  while(cin>>x&&x!=0){
    a=x; 
    cin>>b; 
    cin>>c;
    if(a==b||a==c&&(a!=1||c!=1||b!=1)){cout<<"wrong"<<endl;}
    if(a>b&&a>c){if(b*b+c*c==a*a)cout<<"right"<<endl;else cout<<"wrong"<<endl;}
    if(b>c&&b>a){if(c*c+a*a==b*b)cout<<"right"<<endl;else cout<<"wrong"<<endl;}
    if(c>a&&c>b){if(a*a+b*b==c*c)cout<<"right"<<endl;else cout<<"wrong"<<endl;}
  }
  
}