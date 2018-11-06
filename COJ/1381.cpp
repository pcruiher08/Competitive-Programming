#include <iomanip>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    float dI,d,v1,v2,m;
    while(n--){
        cin>>d>>v1>>v2>>m;
        dI=d/(v1+v2)*m;
       cout << fixed << setprecision(2) << dI<<endl;
    }
}