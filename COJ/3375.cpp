#include <iostream>
#include <string.h>
using namespace std;



int main()
//Caribbean Naebbirac
{
    int n;
    cin>>n;
    while(n--){
    string s1;
    string s2;
    cin>>s1>>s2;
    char e1[s1.size()];
    char e2[s2.size()];
    int suma=0;
    
    for(int i=0; i<s1.size(); i++){
        e1[i]=s1[i];
        e2[i]=s2[i];
    }
    
    for(int i=0; i<s1.size(); i++){
        if(e1[i]!=e2[i]) suma++;
    }
    cout<<suma<<endl;
    }
}