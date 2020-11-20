#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){
sync;

string a,b,c; 

cin>>a>>b>>c; 

if(a=="vertebrado"){
    if(b=="ave"){
        if(c=="carnivoro"){
            cout<<"aguia";
        }else{
            cout<<"pomba";
        }
    }else{
        if(c=="onivoro"){
            cout<<"homem";
        }else{
            cout<<"vaca";
        }
    }
}else{
    if(b=="inseto"){
        if(c=="hematofago"){
            cout<<"pulga";
        }else{
            cout<<"lagarta";
        }
    }else{
        if(c=="hematofago"){
            cout<<"sanguessuga";
        }else{
            cout<<"minhoca";
        }
    }
}
return 0;
}