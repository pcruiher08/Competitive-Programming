#include <iostream>
#include <iomanip>
#include <iostream>
using namespace std;
int main(){
    string s;
    int pro=1;
    cin>>s;
    for(int i=0; i<s.length(); i++)
        if(isupper(s[i]))
        pro=pro*(int(s[i]-64))%26;
    cout << setfill('0') << setw(2) << pro;
}