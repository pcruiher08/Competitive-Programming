#include <iostream>
using namespace std;


bool paraArriba(int a[], int lenght){
    for(int i=0; i<lenght-1; i++){
        if(a[i+1]!=a[i]+1)
            return false;
    }
    
    return true;
}


/*
 5
 1 2 3 4 5
 2 3 4 5 6
 1 4 4 4 5
 1 3 4 5 6
 1 2 2 3 6
 
6
 1 2 3 4 5
 2 3 4 5 6
 1 4 4 4 5
 1 3 4 5 6
 1 2 2 3 6
 1 2 3 4 5
 */

int main(){
    int n;
    cin>>n;
    int p=n;
    int a[5];
    
    while(n--){
        for(int i=0; i<5; i++){
            cin>>a[i];
        }

        if(paraArriba(a,5)){
            cout<<"Y"<<endl;
        }else{
            cout<<"N"<<endl;
        }
        
    }
}