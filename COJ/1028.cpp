

#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    string izq;
    string der;
    int correctos = 0;
    bool no = false;
    int k =0;
    while(cin>>izq>>der){
        for(int i=0; i<izq.length(); i++){
            for(int j=k; j<der.length(); j++){
                if(izq[i]==der[j]){
                    k=j+1;
                    correctos++;
                    break;
                }
            }
        }
        if(correctos==izq.length()){
            cout<<"Yes"<<endl;
            correctos=0;
            k=0;
        }else{
            cout<<"No"<<endl;
            correctos=0;
            k=0;
        }
    }
    
}
/*
 sequence subsequence
 person compression
 VERDI vivaVittorioEmanueleReDiItalia
 caseDoesMatter CaseDoesMatter
 */

