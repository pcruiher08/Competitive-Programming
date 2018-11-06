//
//  main.cpp
//  OmegaUpConcursoSkyNet
//
//  Created by Pablo César Ruíz Hernández on 9/29/18.
//  Copyright © 2018 Pablo César Ruíz Hernández. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 987654321
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

bool func(char uno, char dos){
    if(uno>dos) return true;
    return false;
}

int main(){
    int x;
    cin>>x;
    while(x--){
        string num;
        cin>>num;
        string izquierda="";
        string derecha="";
        ll sum,max;
        ll n = num.length();
        char s[17];
        if(n==1) goto aqui;
        for(int i=0; i<n; i++){
            s[i] = num[i];
        }
        sort(s,s+n, func);
        
        derecha+=s[n-1];
        for(int i=0; i<n-1; i++)
            izquierda+=s[i];
        
        max = stoll(izquierda);
        
        sum = max+stoll(derecha);
        cout<<sum<<endl;
        continue;
    aqui: cout<<num<<endl;
        
    }
}