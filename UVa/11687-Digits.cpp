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

int main(){
sync;
string s; 
ull cuenta = 0;
int medida;
while(cin>>s){
    if(s=="END")return 0;
    medida = s.length();
    cuenta = 1;
    //cout<<"fuaaaa: "<<floor(log10(medida))+1<<endl;
    //medida = floor(log10(medida))+1 ;
    if (s == "1") cuenta = 0;
    while(floor(log10(medida))+1 != medida && s != "1"){
        if(s=="1"){cout<<0<<endl; return 0;}
        cuenta++;
        medida = floor(log10(medida))+1;
        //cout<<"m: "<<medida<<endl;
    }
    cout<<++cuenta<<endl;
}

return 0;
}