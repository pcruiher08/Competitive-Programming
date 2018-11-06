
#include <iostream>
#include <algorithm>
using namespace std;

void voltea(string &str)
{
    int n = str.length();
    for (int i=0; i<n/2; i++)
        swap(str[i], str[n-i-1]);
}

int main() {
    int n;
    cin>>n;
    string s;
    string vacio;
    
    int longitud = 0;
    int n1 = 0;
    int cuenta = 0;
    while(n!=0){
        
        cin>>s;
        longitud = (int)(s.length())/n;
        n1 = longitud;
        
        while(cuenta<=n){
            vacio = s.substr(0, longitud);
            voltea(vacio);
            cout<<vacio;
            s.erase(0,longitud);
            cuenta++;
  
        }
        cout<<endl;
        cuenta=0;
        cin>>n;
    }
}