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
int n = 0;

bool isVowel(char ch) { 
       return ( ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'); 
}

bool isNumber(char ch){
        return ( ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9');
}

bool consecChar(string a){
    FOR(i,0,n-1,1)if(a[i]==a[i+1])return false;
    return true;
}

bool hasNumber(string a){
    FOR(i,0,n,1)if(isNumber(a[i])) return true;
    return false;
}

bool hasVowel(string a){
    FOR(i,0,n,1)if(isVowel(a[i])) return true;
    return false;
}

int main(){
sync;
cin>>n; 
string a; cin>>a;
if(hasVowel(a)&&hasNumber(a)&&consecChar(a)){
    cout<<"SEGURO"<<endl;
}else{
    cout<<"INSEGURO"<<endl;
}
return 0;
}