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
    int len; cin>>len;
    string copy; cin>>copy;
    set<char> s; 
    for(int i = 0; i < len; i++){
        s.insert(copy[i]);
    }
    map<char, char> m;
    vector<char> translate;
    for(auto it : s){
        translate.push_back(it);
    }
    for(int i = 0; i <= translate.size() / 2; i++){
        m[translate[i]] = translate[translate.size() - i - 1];
        m[translate[translate.size() - i - 1]] = translate[i];
    }

    for(int i = 0; i < len; i++){
        cout<<m[copy[i]];
    }cout<<endl;

}
return 0;
}