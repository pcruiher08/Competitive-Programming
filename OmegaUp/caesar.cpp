#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int l=0,indice=0,s=0;
    string a="",b="";
    cin>>l>>a>>b;
    int mx=0;
    int buck[26];
    for(int i=0; i<26; i++){
        buck[i]=0;
    }

    indice=0;
    string alf="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;i<l;i++){
        s=abs((b[i])-(a[i]));
        buck[s]+=1;
    }
    for(int i=0;i<26;i++){
        if(buck[i]>mx){
            mx=buck[i];
            indice=i;
        }
    }
    cout<<indice<<endl;
    for(int i=0;i<l;i++){
        cout<<alf[(a[i]-'A'+indice)%26];
    }
    cout<<endl;
return 0;
}