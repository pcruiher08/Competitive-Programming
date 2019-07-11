#include <iostream>

using namespace std;

int main() {
    int lee;
    cin>>lee;
    int superior = (lee>>1) + ((lee&1) ? 2 : 1);
    cout<<lee<<":"<<endl;
    for (int i = 2; i < superior; i++){
        int relec = lee % ((i << 1) - 1);
        if (relec == 0 || relec == i) 
        cout<<i<<","<<i-1<<endl;
        if (lee % i == 0) 
        cout<<i<<","<<i<<endl;
    }
}