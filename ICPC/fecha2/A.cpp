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

int gauss(int n){
    if(n<0) return 0;
    return n*(n+1)*0.5;
}


int main(){
sync;


int a,b,c; cin>>a>>b>>c;


int rangeSum = gauss(c) - gauss(b-1);
cout<<rangeSum<<endl;

double avg = rangeSum / (1.0 * (c - (b - 1) ));
double error = 0;

if((c - (b - 1) ) != 1){
    error = floor(avg) / (c - (b - 1) );
}


double newErr =  ceil(avg) / (c + 1);
newErr = 0;
int sumOfValids = 0;
double constante = 1.0/(c-b);
for(int i=b; i<=c; i++){
    if(i > b && i < c){
    newErr += constante * i;
    sumOfValids += i;
    cout<<"e "<< constante * i <<endl;
    }
}

cout<<newErr<<endl;
cout<< a/newErr <<endl;
cout<<sumOfValids*1.0 / rangeSum<<endl;
cout<< fixed << setprecision(7) << (a/avg + sumOfValids*1.0 / rangeSum) <<endl;

/*
1/3
6/11
0/1

*/
return 0;
}

