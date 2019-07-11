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
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){
    sync;
    int n; 
    int k;
    cin>>k;
    while(k--){
        cin>>n;
        if(n==1) cout<<"Enero";
        if(n==2) cout<<"Febrero";
        if(n==3) cout<<"Marzo";
        if(n==4) cout<<"Abril";
        if(n==5) cout<<"Mayo";
        if(n==6) cout<<"Junio";
        if(n==7) cout<<"Julio";
        if(n==8) cout<<"Agosto";
        if(n==9) cout<<"Septiembre";
        if(n==10) cout<<"Octubre";
        if(n==11) cout<<"Noviembre";
        if(n==12) cout<<"Diciembre";
        if(n<1||n>12) cout<<"Error";
        cout<<endl;
    }
}