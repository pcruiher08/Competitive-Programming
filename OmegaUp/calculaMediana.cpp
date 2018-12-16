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
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){
sync;
vi v;
int x;
string s;
getline(cin,s);

int newIndex = 0;

for(int i=0; i<s.length(); i++){
  if(s[i]==' '){
    newIndex = i;
    i-=(newIndex-1);
    v.pb(atoi(s.substr(0,newIndex+1).c_str()));
    s.erase(0,newIndex);
  }
}
v.pb(atoi(s.c_str()));
//1000 1 900 2 800 3 4 5 6 7 101 102 321


sort(v.begin(),v.end());

int len = v.size();

if(len%2==0){
  //cout<<ceil((v[v.size()/2]+v[v.size()/2+1])/2)<<endl;
  cout<<(floor(v[(v.size()+1)/2-1])+ceil(v[(v.size()+1)/2]))/2<<endl;
  //cout<<floor(v[(v.size()+1)/2-1])<<endl;
  //cout<<ceil(v[(v.size()+1)/2])<<endl;
}else{
cout<<v[v.size()/2];
}
return 0;
}