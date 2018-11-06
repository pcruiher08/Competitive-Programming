#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;



int main(){
    int n;
    cin>>n;
    while(n--){
    int a;
    cin>>a;
    cout<<fixed << setprecision(4)<<1/(a*a*1.0)<<endl;
    }
}