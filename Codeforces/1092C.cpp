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

struct s{
    string a;
    int tam;
    int pos;
    bool suf;
    bool pref;
};


//WRONG ANSWER
bool func1(s a, s b){
    return a.tam<b.tam;
}

bool func2(s a, s b){
    return a.pos<b.pos;
}

int main(){
sync;
int n;
cin>>n;

s palabras[2*n];
FOR(i,0,2*n-2,1){
    cin>>palabras[i].a;
    palabras[i].pos = i+1;
    palabras[i].tam = palabras[i].a.length();
}
cout<<"...."<<endl;
sort(palabras, palabras+2*n-2, func1);

FOR(i,0,2*n-2,1)palabras[i].suf = (i%2==0), palabras[i].pref = (i%2==1);
FOR(i,0,2*n-2,1)cout<<palabras[i].a<<"-"<<palabras[i].suf<<endl;
cout<<"...."<<endl;
sort(palabras, palabras+2*n-2, func2);
FOR(i,0,2*n-2,1)cout<<palabras[i].a<<"-"<<palabras[i].suf<<endl;
FOR(i,0,2*n-2,1)cout<<(palabras[i].suf?'S':'P');
cout<<endl;

return 0;
}