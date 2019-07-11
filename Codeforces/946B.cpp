#include <iostream>
using namespace std;
/*
 If a = 0 or b = 0, end the process. Otherwise, go to step 2;
 If a ≥ 2·b, then set the value of a to a - 2·b, and repeat step 1. Otherwise, go to step 3;
 If b ≥ 2·a, then set the value of b to b - 2·a, and repeat step 1. Otherwise, end the process.
 */
void func(long long &a, long long &b){
    bool ha = true;
    
    while(ha){
    if(a==0||b==0){
        return;
        //break;
    }else{
        if(a>=2*b){
            a%=2*b;
            //1
            //cout<<a<<endl;
            //func(a,b);
            //ha = false;
        }else{
            if(b>=2*a){
                b%=2*a;
                //1
                //ha=false;
                //func(a,b);
            }else{
                return; //break;
            }
        }
    }
}
}


int main() {
    long long a,b;
    cin>>a>>b;
    func(a,b);

    
    
    
    
    cout<<a<<" "<<b;
    return 0;
}