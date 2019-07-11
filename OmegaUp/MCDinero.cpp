#include <iostream>
using namespace std;

int main(){
    int rows;
    cin>>rows;
    for(int i = 1; i <= rows; ++i){
        for(int j = 1; j <= i; ++j){
            cout << "$";
        }
        cout<<endl;
    }
        for(int i = rows-1; i >= 1; --i){
        for(int j = 1; j <= i; ++j){
            cout <<"$";
        }
        cout << endl;
    }
}