#include <iostream>

using namespace std;

int main()
{
int n;
cin>>n;
cout<<n;
cout<<" ";
while(n!=1){
if(n%2==0){
    n=n/2;
    cout<<n;
    cout<<" ";
}else{
    n=(n*3)+1;
    cout<<n;
    cout<<" ";
}
}

   return 0;
}