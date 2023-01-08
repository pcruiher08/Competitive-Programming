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
#include <regex>
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
 
string simplify(string s){
    
    regex letters("abababab|babababa");
    //cout<<s<<endl;
    while(regex_search(s,letters)){
        string replacement = "";
        regex_replace(back_inserter(replacement),s.begin(), s.end(),letters,"");
        s = replacement;
    }
    return s;
 
}
 
int main(){
sync;
 
 
//a === x,y -> y,x
//b === x,y -> n-x+1, y
 
ll n,q; cin>>n>>q;
string ristra = "";
while(q--){
    char query; cin>>query;
 
    if(query == 'r'){
        
        char lec; cin>>lec;
        ll acutalSize = ristra.length();
        
        if(lec == 'c'){

            if(acutalSize > 0 && ristra[acutalSize - 1] == 'b'){
                ristra.pop_back();
                if(ristra.length() > 0 && ristra[ristra.length() - 1] == 'a'){
                    ristra.pop_back();
                    ristra += "b";
                }else{
                    ristra += "ab";
                }
            }else{
                ristra += "bab";
            }
            
        }else if(lec == 'd'){

            if(acutalSize > 0 && ristra[acutalSize - 1] == 'a'){
                ristra.pop_back();
                if(ristra.length() > 0 && ristra[ristra.length() - 1] == 'b'){
                    ristra.pop_back();
                    ristra += "a";
                }else{
                    ristra += "ba";
                }
            }else{
                ristra += "aba";
            }
            
        }else{
            if(ristra[acutalSize - 1] == lec && acutalSize > 0){
                ristra.pop_back();
            }else{
                ristra += lec;
            }
        }
  
    }else{
        ll x, y; cin>>x>>y;
        ristra = simplify(ristra);
        //cout<<ristra<<endl;
        ROF(i,0,ristra.length(),1){
 
            ll xaux = x;
 
            if(ristra[i] == 'a'){
                x = y;
                y = xaux;
            }else if(ristra[i] == 'b'){
                x = x;
                y = n - y + 1;
            }
        }
 
        cout<<(x - 1) * n + (y - 1) + 1 <<endl;
 
    }
}
return 0;
}
 
