

#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void burbuja(int a[], int n){
    int c, d, t;
    for(c=0; c<(n-1); c++){
        for(d=0; d<n-c-1; d++){
            if(a[d] > a[d+1]){
                t=a[d];
                a[d]=a[d+1];
                a[d+1]=t;
            }
        }
    }
}


int main() {
    string s;
    
    int n;
    cin>>n;
    int vks[n][3];
    
    
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>s;
            
            int vaca = 0;
            for(int i=0; i<s.length(); i++){
                vaca+=s[i];
            }
            vks[i][j]=vaca;
        }
    }

    for(int i=0; i<n; i++){
        burbuja(vks[i], 3);
    }

    
    for(int i=0; i<n;i++){
        for(int j=0; j<3; j++){
        }
    }
    
    int sum[n];
    for(int i = 0; i<n; i++){
        sum[i]=vks[i][0]*vks[i][1]*vks[i][2];
    }

    vector <int> v;
    int cuen =0;
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            if(sum[i]==sum[j]) cuen++;
        }
        v.push_back(cuen);
        cuen=0;
    }
    sort(v.begin(),v.end());
    cout<<v[v.size()-1];

    
}

