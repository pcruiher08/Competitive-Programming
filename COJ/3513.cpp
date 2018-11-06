#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        int arr[k+1];
        for(int ie=1; ie<=k; ie++)
            cin>>arr[ie];
        int apestoso1=0, apestoso2=0;
        for(int j=1; j<=k; j++){
            if(j==arr[arr[j]]){
                apestoso1 = arr[j];
                apestoso2 = arr[arr[j]];
                break;
            }
        }
        if(apestoso1>apestoso2)
            cout<<"Case #"<<i+1<<": "<<apestoso2<<" "<<apestoso1<<endl;
        else
            cout<<"Case #"<<i+1<<": "<<apestoso1<<" "<<apestoso2<<endl;
    }
}

