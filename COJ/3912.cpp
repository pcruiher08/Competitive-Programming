#include <iostream>
using namespace std;
int main(){
    
    string a;
    
    cin>>a;
    char e;
    
    for(int i=0; i<a.size(); i++){
        if(a[i]=='i'|| a[i]=='I'){ e = 'N'; break;
        }
        else e='S';
    }
    cout<<e;
    
    
}