#include <iostream>
#include <cmath>
using namespace std;

char tablero[9][9];
int X[9];

bool esValido()
{
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            if(i != j){
                if(X[i] == X[j] || abs(X[j] - X[i]) == abs(j - i))
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cin >> tablero[i][j];
            if(tablero[i][j] == '*')
                X[j] = i;
        }
    }
    if(esValido())
        cout << "valid\n";
    else
        cout << "invalid\n";
    return 0;
}