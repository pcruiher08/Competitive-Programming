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
#include <bitset>
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

unsigned int rightBitPos(bitset<10> b){

    for(int i = 9; i >= 0; i--){
        if(!b[i]){
            return i;
        }
    }
    return -1;

}

unsigned int leftBitPos(bitset<10> b){
    for(int i = 0; i < 10; i++){
        if(!b[i]){
            return i;
        }
    }
    return -1;
}



int main(){
sync;
int n; cin>>n;

bitset<10> b(0);

while(n--){

    char lec; cin>>lec;
    if(lec == 'L'){
        int izqpos = leftBitPos(b);
        b[izqpos] = 1;

    }else if(lec == 'R'){
        int derpos = rightBitPos(b);
        b[derpos] = 1;
    }else{
        int pos = lec - '1' + 1;
        b[pos] = 0;
    }

    
}
auto res = b.to_string();
reverse(res.begin(), res.end());
cout<<res<<endl;

return 0;
}