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
while(n--){
    int candies; cin>>candies;
    int uno = 0, dos = 0;
    bool res = 0;

    while(candies--){
        
        int a; cin>>a;
        if(a == 1){
            uno++;
        }else{
            dos++;
        }
    }
    if(dos % 2 == 0){
        if(uno % 2 == 0){
            res = 1;
        }else{
            res = 0;
        }
    }else{
        if(uno >= 2 && uno % 2 == 0){
            res = 1;
        }
    }
    cout<<(res?"YES":"NO")<<endl;
}
return 0;
}