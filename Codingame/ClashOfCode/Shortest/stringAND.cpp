#include <iostream>
using namespace std;int main(){string a,b;cin>>a>>b;string n="";for(int i=0;i<a.length();i++)n+=(a[i]=='1'&&b[i]=='1'?'1':'0');cout<<n;}