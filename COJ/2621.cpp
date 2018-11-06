#include <iostream>
using namespace std; 
int main(){
    int n; 
    int c=0; 
    cin>>n;
    while(n/=2){
        c++;
    }
    cout<<++c;
}