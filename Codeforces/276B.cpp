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
string s; cin>>s;

int arr[26];
memset(arr,0,sizeof(arr));
FOR(i,0,s.length(),1){
    arr[s[i]-'a']++;
}
int pares = 0; int impares = 0;

FOR(i,0,26,1){
    if(arr[i]&1){
        impares++;
    }else{
        pares++;
    }
}

int movimientosNecesarios = impares - 1;

cout<<(impares&1 || impares < 2?"First":"Second")<<endl;

return 0;
}