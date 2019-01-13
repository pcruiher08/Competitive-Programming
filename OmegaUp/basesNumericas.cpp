
#include <iostream>

using namespace std;

int main(){


int n, base; cin>>n>>base;

while(n!=0){
    cout<<(n%base);
    n/=base;
}



}