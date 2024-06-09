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


int main(){
    sync;

    int n, t;
    cin>>n>>t;
    vector<int> v;
    int st[n][100]; //sparse table
    for(int i = 0; i < n; i++){
        int lec; cin>>lec;
        st[i][0] = lec;
        v.push_back(lec);
    }
    //calculate logs
    /*
    int lg[10001];
    lg[1] = 0;
    for(int i = 2; i < 10001; i++){
        lg[i] = lg[i / 2] + 1;
    }
    */

    //fill sparse table
    
    for(int j = 1; (1<<j) <= n; j++){
        for(int i = 0; i + (1<<(j)) - 1 < n; i++){
            st[i][j] = min(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
        }
    }

    


    for(int i = 0; i < t; i++){
        int L, R; cin>>L>>R;
        L--;
        R--;
        int tam = log2(R - L + 1);
        //cout<<"TAM "<<tam<<endl;
        //query sparse table
        cout<<min(st[L][tam], st[R - (1<<tam) + 1][tam])<<endl;
    }
return 0;
}