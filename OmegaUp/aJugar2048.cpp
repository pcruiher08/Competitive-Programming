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

int n;
cin>>n;
stack <int> s;
int x;
int aux = 0;
while(n--){
    cin>>x;
    aux = x;
    while(!s.empty()&&s.top()==aux){
        aux += aux;
        s.pop();
    }
    s.push(aux);
    if(s.empty())s.push(x);
}

cout<<s.size()<<endl;
while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
}

return 0;
}