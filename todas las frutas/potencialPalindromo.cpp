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

bool isPotentialPal(string str, int len){
    int mascaraDeBits[26];
    for(int i=0; i<26; i++){
        mascaraDeBits[i] = 0;
    }
    //                  a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
    // mascaraDeBits = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    for(int i=0; i<len; i++){
        mascaraDeBits[ str[i] - 97 ]++;
    }
    //                  a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
    // mascaraDeBits = {2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}
    int cuantosImpares = 0;
    for(int i=0; i<26; i++){
        if(mascaraDeBits[i]%2 == 1){
            cuantosImpares++;
        }
    }
    if(cuantosImpares>1){
        return false;
    }
    return true;
}

int main(){
sync;

string str = "azabbzccpdde";

bool flag = isPotentialPal(str, str.length());

if(flag){
    cout<<"si"<<endl;
}else{
    cout<<"no"<<endl;
}


return 0;
}