#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    n = n%2;
    string first,second;
    cin>>first>>second;
  

    for (int i=0;i<first.size();i++){
        if ( ((first[i]==second[i])&&n) || (!(first[i]==second[i])&&!n) ){
            cout << "Deletion failed" << endl;
            return 0;
        }
    }
    cout << "Deletion succeeded" << endl;
    return 0;
}