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
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

void fastscan(int &x){
    char ch; bool f= 0; int a=0;
    while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));
    if(ch!='-')a*=10,a+=ch-'0';else f=1;
    while(((ch=getchar())>='0')&&(ch<='9'))a*=10, a+=ch-'0';
    if(f)a=-a;x=a;
}

class RMQ {
private:
//int SpT[100000][20];
  int *SpT[20];
  vi _A;
public:
  RMQ(int n, vi A) {
      for (int i = 0; i < 20; i++) {
          SpT[i] = new int[500000];
      }
    for (int i = 0; i < n; i++) {
      _A.pb(A[i]);
      SpT[0][i] = i;
    } 
    for (int j = 1; (1<<j) <= n; j++)
      for (int i = 0; i + (1<<j) - 1 < n; i++)
        if (_A[SpT[j-1][i]] < _A[SpT[j-1][i+(1<<(j-1))]])
          SpT[j][i] = SpT[j-1][i];
        else
          SpT[j][i] = SpT[j-1][i+(1<<(j-1))];
  }

  int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));
    if (_A[SpT[k][i]] <= _A[SpT[k][j-(1<<k)+1]]) return SpT[k][i];
    else return SpT[k][j-(1<<k)+1];
} };

int main(){
sync;
int n, k, a, b, aux; fastscan(n);  

vi arr; 
FOR(i,0,n,1){fastscan(aux); arr.pb(aux);}
RMQ arbolitoDeNavidad(n,arr);
fastscan(k);
FOR(i,0,k,1){fastscan(a); fastscan(b); cout<<arr[arbolitoDeNavidad.query(a-1,b-1)]<<endl;}

return 0;
}