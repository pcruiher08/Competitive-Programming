#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int aux=n;
    int arr[n+2];
    arr[0]=1;
    int suma=0;
    arr[n+1]=1;
    while(n--){
        cin>>arr[aux-n];
        //n--;
    }
    
    
    for(int i=0; i<aux+1; i++){
        suma+=abs((arr[i]-arr[i+1]));
        //cout<<arr[i];
    }
    cout<<suma;
}