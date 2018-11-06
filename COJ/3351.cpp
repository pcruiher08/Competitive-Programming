#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string in;
    for (int i = 0; i < n; i++){
        bool x = true;
        cin >> in;
        if(in != string(in.rbegin(), in.rend()))x=false;
        
        if(x)
        for (int j = 0; j < in.length(); j++){
            if ( !(isupper(in[j])) || (in[j] >= 66 && in[j] <= 71) || (in[j] >= 74 && in[j] <= 76) || (in[j] == 'N') || (in[j] >= 80 && in[j] <= 83) || (in[j] == 'Z')){
                x = false;
            }
        }
        if (x){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}