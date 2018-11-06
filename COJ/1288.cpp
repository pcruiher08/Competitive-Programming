#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;



int main(){
    
    int p;
    cin>>p;
    while(p--){
    string n;
    cin>>n;
    long int suma = 0;
    char a[n.size()];
    
    for(int i=0; i<n.size(); i++){
        a[i]=n[i];
        suma+=a[i]-48;
    }
    
    if(suma%3==0&&a[n.size()-1]%2==0){
    cout<<"YES"<<endl;
    }else{
    cout<<"NO"<<endl;
    }
    
    }
    
        
    
}