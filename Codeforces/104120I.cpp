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
#define EPS 1e-9
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
 
const int N=1e6;
int K=log2(N);
int lookup[N][22];
int arr[N];
void build()
{
    for(int i=0;i<N;i++)
    lookup[i][0]=arr[i];

    for(int j=1;j<=K;j++){
        for (int i = 0; i + (1 << j) <= N; i++)
        lookup[i][j] = max(lookup[i][j-1],lookup[i + (1 << (j - 1))][j - 1]);
    }
}
int query(int L,int R)
{
    int j = log2(R-L+1);
    int maximum = max(lookup[L][j], lookup[R-(1 << j) + 1][j]);
    return maximum;
}

int main(){
sync;
int n; fastscan(n);

FOR(i,0,n,1){int lec; fastscan(arr[i]); }
//int* st = constructST(arr, n);
//SqrtTree st(arr);
build();
 
int queries; fastscan(queries);
while(queries--){
    int m; fastscan(m);
    vector<int> indices;
    FOR(i,0,m,1){
        int lec; fastscan(lec);
        indices.pb(lec-1);
    }
    ll suma = 0;
 

    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            //cout<<"indices buscando = "<<indices[i]<<" "<<indices[j]<<endl;
            //cout<<"valores(";
            //FOR(k,indices[i],indices[j]+1,1)cout<<arr[k]<<(k<indices[j]?",":")");
            //cout<<endl;
      
            ll RMQ = query(indices[i], indices[j]);
            cout<<"RMQ = "<<RMQ<<endl;
     
            suma += RMQ;
        }
    }
    printf("%lld\n",suma);
}
return 0;
}
/*
6
2 7 5 8 1 2
1
2
1 6
*/