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
    int a;
    cin>>a;
    while(a--){
        string n; 
        cin>>n;
        string mensaje = "AA";
        mensaje+=n;
        mensaje+="AA";
        bool mask[100007] = {false};
        FOR(i,0,mensaje.length(),1)
            if(mensaje[i]=='B'){
                if(mensaje[i-1]=='W')
                    mask[i-1]=true;
                if(mensaje[i-2]=='W')
                    mask[i-2]=true;
                if(mensaje[i+2]=='W')
                    mask[i+2]=true;
                if(mensaje[i+1]=='W')
                    mask[i+1]=true;
            }
        int cuenta = 0;
        FOR(i,0,mensaje.length()+2,1)if(mask[i])cuenta++;
        cout<<cuenta<<endl;
    }
}