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

bool isVowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}


int main(){
sync;
string s, t;
cin>>s>>t;

if(s.length()!=t.length()){
    cout<<"No"<<endl;
    return 0;
}

FOR(i,0,s.length(),1){
    if(!((isVowel(s[i])&&isVowel(t[i]))||(!isVowel(s[i])&&!isVowel(t[i])))){
        cout<<"No"<<endl;
        return 0;
    }
}
cout<<"Yes"<<endl;
return 0;
}