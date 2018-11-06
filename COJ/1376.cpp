#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
        string nuevo;
        cin>>nuevo;
        string old = nuevo;
        next_permutation(nuevo.begin(),nuevo.end());
        if(nuevo==old){
          cout<<0;
        }else{
          cout<<nuevo;
        }
}