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
const int n = 8;
int lista[] = {2,3,4,5,3,1,1,3};

//tamanio n * log(n)
int st[n + 1][4];
int main(){
sync;



for(int i = 0; i < n; i++){
    st[i][0] = lista[i];
}

for(int j = 1; j < 3; j++){
    for(int i = 0; i  + (1<<j) - 1 < n ; i++){
        st[i][j] = max(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]);
    }
}
// 

cout<<"SPARSE TABLE"<<endl;
for(int j = 0; j < 3; j++){
    for(int i = 0; i < n; i++){
        cout<<st[i][j]<<" ";
    }cout<<endl;
}

int L = 0; int R = 6;

int tam = R - L + 1;

tam = 2;

cout<<max(st[L][tam], st[R - (1<<tam) + 1][tam]);

//answer queries in the form (L, R)



return 0;
}