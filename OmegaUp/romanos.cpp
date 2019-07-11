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
int n; cin>>n;
int uno = 0,cinco = 0,diez = 0,cincuenta = 0,cien = 0;
uno = n%5;
cout<<uno<<endl;
n-=uno;
cinco = n%10;
cinco %=5;
cout<<cinco<<endl;
n-=cinco;
diez=n%50;
diez%=10;
diez%=5;
cout<<diez<<endl;
n-=diez;
cincuenta = n%100;
cincuenta%=50;
cincuenta%=10;
cincuenta%=5;
cout<<cincuenta<<endl;
n-=cincuenta;
cien = n;
cout<<cien<<endl;

FOR(i,0,cien,1)cout<<"C";
FOR(i,0,cincuenta,1)cout<<"L";
FOR(i,0,diez,1)cout<<"X";
FOR(i,0,cinco,1)cout<<"V";
FOR(i,0,uno,1)cout<<"I";
cout<<endl;

return 0;
}