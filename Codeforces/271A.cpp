#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
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
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){
sync;
int year; cin>>year; 
stringstream s; 
string vacio = "";
FOR(i,year+1,90010,1){
    year++;
    int p1,p2,p3,p4,help;
    help = i; 
    p1 = help%10;
    help /= 10; 
    p2 = help%10; 
    help /= 10; 
    p3 = help %10; 
    help /= 10; 
    p4 = help %10; 
    if((p1 != p2) && (p1 != p3) && (p1 != p4) && (p2 != p3) && (p2 != p4) && (p3 != p4)){
        cout<<year<<endl; 
        return 0;
    } 
}
return 0;
}