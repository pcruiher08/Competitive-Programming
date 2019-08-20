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
string year; cin>>year; 
int d1, d2, d3, d4; 
d1 = year[0] - '0'; 
d2 = year[1] - '0'; 
d3 = year[2] - '0'; 
d4 = year[3] - '0';
cout<<"orig: "<<year<<endl;
int totYear = 0;
totYear += d1 * 1000 + d2 * 100 + d3 * 10 + d4;
cout<<"d1: " <<d1<<endl;
cout<<"d2: " <<d2<<endl;
cout<<"d3: " <<d3<<endl;
cout<<"d4: " <<d4<<endl;
cout<<totYear<<endl;
return 0;
}