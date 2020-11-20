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
    string n,ap,am,an,d,m;
    cin>>n>>ap>>am>>d>>m>>an;
    char voc = '-';
    for(int i=1; i<ap.length(); i++){ 
        if(ap[i]=='A'||ap[i]=='E'||ap[i]=='I'||ap[i]=='O'||ap[i]=='U'){
            voc = ap[i];
            break;
        }
    }
    cout<<ap[0]<<voc<<am[0]<<n[0]<<an[2]<<an[3]<<m<<d;
    return 0;
}
/*
MARIO ESPARZA RUIZ 
14 10 2001
*/