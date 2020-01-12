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
#define FOR(m,s,n,u) for(ull m=s; m<n; m+=u)
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

string inToBase(ull n, ull base){
    char base12[] = "0123456789AB";
    string res;
    while(n>0){
        int rem = n%base;
        n/=base;
        res.insert(res.begin(),base12[rem]);
    }

    if(res=="") return "0";
    return res;
}

bool isPandigital(string n, ull base){
    int arr[base];
    FOR(i,0,base,1)arr[i] = 0;
    FOR(i,0,n.length(),1)arr[n[i]-'0']++;
 
    FOR(i,0,base,1)if(!arr[i])return false;
    return true;
}

bool isNPandigital(ull num, ull n){


    FOR(i,2,n,1){
        if(!isPandigital(inToBase(num,i),i)){
            return false;
       
        }
    }

    return true;
}

void print(ull num, ull maxBase){
    FOR(i,2,maxBase,1){
        cout<<inToBase(num,i)<<" ";
    }
}

int main(){
sync;
ull cuenta = 0;
ull i = 11123456789;
while(cuenta<11){
    if(isNPandigital(i,11)){
        cuenta++;
        cout<<"("<<i<<"): ";
        print(i,11);
        cout<<endl;
    }
    i++;
}
return 0;
}