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
int n; cin>>n;
int cuenta = 0;

while(n){
    if(n >= 100){
        cuenta += int(floor(n / 100));
        n = n % 100;
    }else if(n >= 20){
        cuenta += int(floor(n / 20));
        n = n % 20;
    }else if(n >= 10){
        cuenta += int(floor(n / 10));
        n = n % 10;
    }else if(n >= 5){
        cuenta += int(floor(n / 5));
        n = n % 5;
    }else{
        cuenta += n;
        n = 0;
    }

}

cout<<cuenta<<endl;

return 0;
}