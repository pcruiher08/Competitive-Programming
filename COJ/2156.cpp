#include <iostream>
using namespace std;
int main(){
    unsigned long long a,b;
    cin>>b>>a;
    if(a<=3&&b==0)
        cout<<"yes";
    else if(a<=3&&b!=0)
        cout<<"no";
    else if(a==4&&b==2)
        cout<<"yes";
    else if(a==4&&b!=2)
        cout<<"no";
    else if(b==a*(a-3)/2)
        cout<<"yes";
    else
        cout<<"no";
    
}
