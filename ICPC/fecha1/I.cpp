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

bool consecNums(string s){
    FOR(i,0,s.length()-1,1){
        if(isdigit(s[i]) && isdigit(s[i+1])){
            //cout<<abs(s[i]  - s[i+1] )<<endl;
            if(abs(s[i] - s[i+1]) == 1){
                return false;
            }
        }
    }
    return true;
}

void process(string s, int asser){
    bool r1 = false, r2=false, r3 = false, r4 = false, r5 = false;
    int mayus =0, minus=0, nums = 0, specials = 0; 
    int largo = s.length();
    FOR(i,0,largo,1){
        if(isupper(s[i]))
            mayus+=1;
        if(islower(s[i]))
            minus+=1;
        if(isdigit(s[i]))
            nums+=1;
        if(s[i]=='.' || s[i]=='#' || s[i]=='$' || s[i]=='%' || s[i]=='/' || s[i]=='(' || s[i] =='&' || s[i] ==')')
            specials+=1;
    }
    r1 = minus >= 1;
    r2 = mayus >= 1;
    r3 = consecNums(s) && nums >= 1;
    r4 = specials >= 1;
    r5 = largo >= 10;
    //cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<" "<<r5<<endl;
    int suma = r1 + r2 + r3 + r4 + r5;
    cout<<"Assertion number #"<<asser<<": ";
    if(suma == 5)
        //#strong
        cout<<"Strong"<<endl;
    else if(suma == 4)
        //#good
        cout<<("Good")<<endl;
    else if(suma == 3)
        //#weak
        cout<<("Weak")<<endl;
    else
        //#rejected
        cout<<("Rejected")<<endl;
}

int main(){
sync;
int n; cin>>n; 
FOR(i,0,n,1){
    string lec; cin>>lec;
    process(lec, i+1);
}
return 0;
}