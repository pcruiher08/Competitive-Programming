#include <iostream>
using namespace std;
int main(){
    int n=8;
    int a[n];
    for(int i=0; i<8; i++){
        cin>>a[i];
    }
    
    int temp =0;
    for(int i=0;i<8;i++){
        if(a[i%8]+a[(i+1)%8]+a[(i+2)%8]+a[(i+3)%8]>temp)
            temp=a[i%8]+a[(i+1)%8]+a[(i+2)%8]+a[(i+3)%8];
    }
    cout<<temp<<endl;
}
