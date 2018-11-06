#include <iostream>
using namespace std;
int main(){
    int n,w,c=0;
    cin>>n>>w;
    for( int i = 0; i < n; i++ )
        c+=i;
    if((n*w)>c){
            cout<<-1<<endl;
        }else{
            c=n*w;
            cout<<c<<endl;
        }
}