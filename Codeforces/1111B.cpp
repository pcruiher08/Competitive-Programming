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
int n, k, m; 
cin>>n>>k>>m;
int x;
vi heroes;
FOR(i,0,n,1)cin>>x, heroes.pb(x);
sort(heroes.begin(), heroes.end());
FOR(i,0,heroes.size(),1)cout<<heroes[i]<<" ";
cout<<endl;

m-=k;

long long sum = k;


FOR(i,m,heroes.size()-1,1)cout<<"heroes[i]: "<<heroes[i+1]<<endl, sum+=heroes[i+1];


if(m<heroes.size())
printf("%.20f",(float)sum/(heroes.size()-m));
else
printf("%.20f",(float)heroes[heroes.size()-1]);

return 0;
}

/*
9 2 8
74578 2746 96295 86884 21198 28655 22503 7868 47942
Output
53820.66666666666400000000
Answer
96295.00000000000000000000
Checker Log
wrong answer expected 96295.000000, found 53820.666667
*/

//sorted: 2746 7868 21198 22503 28655 47942 74578 86884 96297