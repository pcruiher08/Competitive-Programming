#include <iostream>
#include <vector>
using namespace std;

bool isUno(int arr[], int n){
    if(n==1||n==2){
        return "Yes";
    }
    vector <char> con;
    
    for(int i=0; i<n-1; i++){
        if(arr[i]<arr[i+1])
            con.push_back('c');
        if(arr[i]==arr[i+1])
            con.push_back('i');
        if(arr[i]>arr[i+1])
            con.push_back('d');
    }
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n-1; j++){
            if(con[i]=='i'&&con[j]=='c')
                return false;
            if((con[i]=='d'&&con[j]=='i')||(con[i]=='d'&&con[j]=='c'))
                return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    int x;
    for(int i=0; i<n; i++){cin>>x; arr[i]=x;}
    cout<<(isUno(arr, n)?"YES":"NO")<<endl;
}