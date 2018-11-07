#include <iostream>

using namespace std;

int main()
{
    int m;
    cin>>m;
    int mensajes[m-1];
    int cuenta = 0;
    while(cuenta<m){
        cin>>mensajes[cuenta];
        cuenta++;
    }
    cuenta=0;
    int contador=0;
    string corazon = "<3";
    string x;
    for(int i=0; i<m; i++){
        for(int p=0; p<mensajes[i]; p++){
            
            x = corazon + x;
        }
       cout << x << endl; 
       x= "";
    }
   return 0;
}
