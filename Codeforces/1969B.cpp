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
    string bi; cin>>bi;
    int p1 = 0, p2 = 1; 
    int res = 0;
    cout<<"case: "<<n<<endl;
    while(p1 < bi.length() && p2 < bi.length()){
        if(bi[p1] == '1'){
            while(bi[p2] == '1') p2++;
            //p2--;
            cout<<"p1: "<<p1<<", p2:"<<p2<<endl;
            res += p2 - p1 + 1;
            char aux = bi[p1];
            bi[p1] = bi[p2];
            bi[p2] = aux;
        }
        p1++; p2++;

    }
    cout<<res<<endl;
}
return 0;
}