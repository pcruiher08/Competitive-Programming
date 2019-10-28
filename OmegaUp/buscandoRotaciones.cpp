#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
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
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;


bool validaDesde(string a, string b, int index){
    FOR(i,0,a.length(),1){
        if(a[i]!=b[(index + i ) % b.length()]) return false;
    }
    return true;
}

vi letrasA(26),letrasB(26);

int main(){
sync;

string a, b; 
cin>>a>>b;



int indice = 0;

if(a.length()==b.length()){
    char busca = a[0];
    FOR(i,0,b.length(),1){
        if(b[i]==busca){
            indice = i;
            if(validaDesde(a,b,indice)){
                //si
                cout<<"Rotacion"<<endl;
                return 0;
            }  
        }

    }
    //nel
    cout<<"No rotacion"<<endl;
    return 0;


}else{
    //nel
    cout<<"No rotacion"<<endl;
    return 0;
}

return 0;
}