#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
bool secuencia(string a1, string a2) {
    int j = 0;
    for (int i=0; i<a2.length()&&j<a1.length(); ++i)
        if (a1[j]==a2[i])
            ++j;
    return j==a1.length();
}

int main(){
    string a1,a2;
    while(cin>>a1>>a2){
        cout<<(secuencia(a1,a2)? "Yes":"No")<<endl;
    }
}