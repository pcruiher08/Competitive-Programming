#include <iostream>
#define ll long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define min(x,y) x<y?x:y
using namespace std;

int num[1000000];
int greatest = 10000000;
int main(){
	int n;
  cin>>n;
  FOR(i,2,n,1)if(num[i]==0)FOR(j,2*i,n+1, i)num[j]=i;
  FOR(i,n-num[n]+1,n+1,1) greatest = min(greatest,i-num[i]+1);
  cout<<greatest<<endl;
} 