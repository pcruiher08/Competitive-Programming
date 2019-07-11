#include <iostream>
using namespace std;
int main() {
    int size;
    int s1,s2,p1,p2;
    cin>>size>>s1>>s2>>p1>>p2;
    
    int j1,j2;
    j1=2*p1+size*s1;
    j2=2*p2+size*s2;
    //cout<<j1<<endl<<j2<<endl;
    
    if(j1<j2){
        cout<<"First";
    }else if(j2<j1){
        cout<<"Second";
    }else{
        cout<<"Friendship";
    }
    
}