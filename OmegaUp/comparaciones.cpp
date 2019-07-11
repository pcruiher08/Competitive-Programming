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
set <int> s;
int x;
FOR(i,0,5,1){cin>>x;s.insert(x);} 


switch (s.size())
{
    case 1:
        cout<<"Identicamente iguales"<<endl;
        break;
    case 2:
        cout<<"Muy iguales"<<endl;
        break;
    case 3:
        cout<<"Iguales"<<endl;
        break;
    case 4:
        cout<<"Diferentes"<<endl;
        break;
    case 5:
        cout<<"Muy diferentes"<<endl;
        break;
}
return 0;
}