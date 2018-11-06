#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    long long int n,m;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n%2==0&&m%2==0){
            if(n>m)
                cout<<'U'<<endl;
            else if(m>=n)
                    cout<<'L'<<endl;
        }
        else if(n%2!=0&&m%2!=0){
            if(n>m)
                cout<<'D'<<endl;
            else if(m>=n)
                cout<<'R'<<endl;
        }else{
            if(n%2==0&&m%2!=0){
                    if(n>m)
                        cout<<'D'<<endl;
                    else
                        cout<<'L'<<endl;
                }
            if(n%2!=0&&m%2==0){
                    if(n<m)
                        cout<<'R'<<endl;
                    else
                        cout<<'U'<<endl;
                }
        }
    }
}