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
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int main(){
sync;
int k; cin>>k;
string s; cin>>s;
int m[26];
FOR(i,0,26,1)m[i]=0;
FOR(i,0,s.length(),1)m[s[i] - 'a']++;


//checa si todos son multiplos de k

FOR(i,0,26,1){
    if(!(m[i] % k == 0 || m[i] == 0)){
        cout<<-1<<endl;
        return 0;
    }
}



string copia = "";
FOR(i,0,26,1){
    int repetidos = m[i] / k;
    FOR(j,0,repetidos,1){
        copia += (char(i + 'a'));
    }
    
}

FOR(i,0,k,1){
    cout<<copia;
}
cout<<endl;
//
return 0;
}