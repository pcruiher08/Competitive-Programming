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
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){

  int n = 1; //cin>>n;

  while(n--){

	string s1;
	string s2;
	cin >> s1 >> s2;
	ull prod1 = 1;
	for (int i=0;i<s1.size();i++){
		prod1 *= (int) (s1[i]-'A'+1);//+1;
		cout<<(s1[i]-'A'+1)<<" ";
		//cout<<s1[i]<<" ";
	}
	//cout<<endl;
	cout<<prod1<<endl;
	ull prod2 = 1;
	for (int i=0;i<s2.size();i++){
		prod2 *= (int) (s2[i]-'A'+1);//+1;
	}
  cout << (prod1%47==prod2%47?"GO":"STAY") << endl;
  }
	return 0;
}