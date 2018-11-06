#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
/*
#include <string>
#include <cctype>
*/
using namespace std;




    
    int main() {
        int n;
        cin>>n;
        
        while(n--){
        
        int num = 0;
        cin >> num;
        
        vector <int> v;
        int fac = 2;
        while (num > 1) {
            if (num % fac == 0) {
                //cout << fac<<endl;
                v.push_back(fac);
                num=num / fac;
            }
            else fac++;
        }
        std::sort(v.begin(), v.end());
        int cuenta = std::unique(v.begin(), v.end()) - v.begin();
        
        cout<<cuenta<<endl;
        }
}