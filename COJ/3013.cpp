
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p=0;
    int k=0;
    while(n>0){
        cin>>k;
        while(k>0){
            p=2*p+1;
            k--;
        }
        cout<<p<<endl;
        p=0;
        n--;
    }

    
}