#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string cadena;
    int lon;
    cin >> cadena;
    lon = cadena.size();
    if(lon % 2 == 0){
        reverse(cadena.begin(), cadena.begin() + lon/2);
        reverse(cadena.begin() + lon/2, cadena.end());
    }
    else {
        reverse(cadena.begin(), cadena.begin() + lon/2);
        reverse(cadena.begin() + lon/2 + 1, cadena.end());
    }
    cout << cadena << "\n";
    return 0;
}