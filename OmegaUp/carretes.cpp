#include <iostream>
using namespace std;

int main(){
int n; cin>>n; 
string a, b; 
cin>>a>>b; 

int distancias = 0; 

for(int i =0; i<n; i++){

    int menor = min(a[i],b[i])-'0';
    int mayor = max(a[i],b[i])-'0';

    distancias += min( mayor - menor, menor + 10 - mayor );

}

cout<<distancias<<endl;


return 0;
}