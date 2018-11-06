#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        int num[a];
        int gan; 
        for(int i=0; i<a; ++i){
            cin>>num[i];
        }
        gan=num[b-1];
        int cu=0;
        for(int i=0; i<a; ++i){
            if(num[i]>=gan&&num[i]>0){
                cu++;
            }
        }
        cout<<cu<<endl;
    }
}