#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin>>n; 
    int upper=0; 
    int lower=0; 
    string let; 
    cin>>let; 
    for(int i=0; i<let.size(); i++){
      if(isupper(let[i])) upper++;
      else lower++;
      
    }
    cout<<upper<<" "; 
    cout<<lower<<endl;
}