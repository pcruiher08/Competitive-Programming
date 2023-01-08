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

long long fact[100001];
long long actual = 1;
long long fac(long long n){
   fact[0]=1;
   fact[1]=1;
   if(n>actual){
   for(long long i=actual; i<=n; i++){
       fact[i]=(fact[i-1]*i)%mod;
   }
   actual = n;
   }
   return fact[n];
}

int main(){
sync;

string a, b;
cin>>a>>b;

int origPlus = 0, origMinus = 0;
int receivedPlus = 0, receivedMinus = 0, receivedQ = 0;

origPlus = count(a.begin(), a.end(), '+');
origMinus = a.length() - origPlus;

receivedPlus = count(b.begin(), b.end(), '+');
receivedMinus = count(b.begin(), b.end(), '-');
receivedQ = b.length() - receivedMinus - receivedPlus;

int difPlus = 0, difMinus = 0;

difPlus = origPlus - receivedPlus;
difMinus = origMinus - receivedMinus;


if(difMinus < 0 || difPlus < 0){
    //0;
    cout<<0<<endl;
}else{
    //cout<<difMinus << " " << difPlus<<" ? = "<<receivedQ<<endl;
    //cout<<(1<<receivedQ)<<endl;
    //cout<<difMinus + difPlus << "C" << min(difMinus, difPlus)<<endl;
    int combi = fac(difMinus + difPlus) / (fac(min(difMinus, difPlus)) * fac(difMinus + difPlus - min(difMinus, difPlus)));
    cout<<fixed<<setprecision(12)<< combi * 1.0 / (1<<receivedQ) <<endl;

}



return 0;
}