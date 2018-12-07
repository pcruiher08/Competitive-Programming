#include <iostream>
//incomplete
using namespace std; 
int main(){
    int n,p;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)a[i]=0;
    while(n--){
        cin>>p;
        cout<<p;
        a[p+1]++;
    }
    for(int i=1;i<10;i++){
        cout<<i<<":";
        cout<<a[i]<<endl;
     }
}