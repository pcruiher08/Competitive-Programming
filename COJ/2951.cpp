#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int n;
set<string>l;
string k;
int main(){
    cin >> n;
    while(n--){
        cin >> k;
        sort(k.begin(),k.end());
        l.insert(k);
    }
    cout << l.size() << endl;
}