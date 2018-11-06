#include <iostream>
#include <math.h>
using namespace std;

int ascendiente(int asce){
    int b=asce;
    int p=1;
    int length=log(asce)+1;
    for(int e=0; e<=length; e++){
        b=asce;
        p=1;
        while (b>9){
            int se=b%10, r=(b%100)/10;
            if(se<r) asce+=p*(se*9-r*9);
            b=asce;
            p*=10;
            b/=p;
        }
    }
    return asce;
}

int main(){
    int n;
    cin>>n;
    int suma=0;
    
    while(n>0){
        n=n-ascendiente(n);
        suma++;
        //cout<<n<<" "<<suma<<endl;
    }
    cout<<suma;
    
    //cout<<suma;
}