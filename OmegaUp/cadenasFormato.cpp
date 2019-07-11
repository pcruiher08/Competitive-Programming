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

bool isVowel(char a){
    return (a=='a'||a=='A'||a=='e'||a=='E'||a=='i'||a=='I'||a=='o'||a=='O'||a=='u'||a=='U');
}

void minusc(string a){
    FOR(i,0,a.length(),1)cout<<(char)tolower(a[i]);
    cout<<endl;
}

void mayus(string a){
    FOR(i,0,a.length(),1)cout<<(char)toupper(a[i]);
    cout<<endl;
}


void titulo(string a){
    cout<<(char)tolower(a[0]);
    FOR(i,1,a.length(),1)cout<<(char)tolower(a[i]);
    cout<<endl;
}

void cap(string a){
    FOR(i,0,a.length(),1)if(a[i]==' '&&i<a.length())cout<<" "<<(char)toupper(a[++i]); else cout<<(char)tolower(a[i]);
    cout<<endl;
}

void change(string a){
    FOR(i,0,a.length(),1)if(isupper(a[i])) cout<<(char)tolower(a[i]); else cout<<(char)toupper(a[i]);
    cout<<endl;
}

int main(){
sync;
string a; getline(cin,a);

minusc(a);
mayus(a);
titulo(a);
cap(a);
change(a);
return 0;
}