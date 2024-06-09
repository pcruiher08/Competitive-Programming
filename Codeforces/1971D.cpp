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
    string lec; cin>>lec;
    int cuenta = 0;
    int p1 = 0;
    bool seenone = false;
    int caseones = 0; 
    int casezeroone = 0;
    int casezeroes = 0;

    while(p1 < lec.length()){
        if(lec[p1] == '1'){
            while(lec[p1] == '1'){
                p1++;
            }
            caseones++;
        }
        if(lec[p1] == '0'){
            while(lec[p1] == '0'){
                p1++;
            }
            casezeroes++;
        }
    }

    //busca 01
    for(int i = 1; i < lec.length(); i++){
        if(lec[i] == '1' && lec[i - 1] == '0'){
            casezeroone++;
        }
    }

    cout<<caseones + casezeroes - bool(casezeroone)<<endl;
    
}

return 0;
}