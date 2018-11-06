#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <ctype.h>
#include <stdio.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long s;
    bool flag;
    string aux;
    cin >> n >> s;
    s %= 26;
    char letras[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cin.ignore();
    //cout << "X es" << letras[25] << endl;
    while(n--){
        getline(cin,aux);
        for(int i = 0; i < aux.size(); i++){
            if(isalpha(aux[i])){
                flag = (int)aux[i] > 96; //Es miniscula
                int pos =(((int)toupper(aux[i]) - 65) - s) % 26;
                while(pos <  0)
                    pos += 26;
                pos %= 26;
                //cout << "La posicion que cambie fue" << pos << endl;
                if(flag)
                    aux[i] = letras[pos];
                else
                    aux[i] = toupper(letras[pos]);
            }
        }
        cout << aux << endl;

    }

	return 0;
}