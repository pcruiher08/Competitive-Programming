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



string s; 
cin>>s; 

int pelota = 1; 
for(int i=0; i<s.length(); i++){
    if(pelota == 1 && s[i]=='A'){
        pelota = 2; 
    }else if(pelota == 1 && s[i]=='C'){
        pelota = 3;
    }else if(pelota == 2 && s[i]=='A'){
        pelota = 1;
    }else if(pelota == 2 && s[i]=='B'){
        pelota = 3 ;
    }else if(pelota == 3 && s[i]=='B'){
        pelota = 2; 
    }else if(pelota == 3 && s[i]=='C'){
        pelota = 1;
    }
}
cout<<pelota;

return 0;
}