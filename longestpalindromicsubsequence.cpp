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

int LPSrecursivo(string s, int i, int j){
    if(i == j) return 1;
    if(s[i] == s[j] && i + 1 == j) return 2;
    if(s[i] == s[j]) return 2 + LPSrecursivo(s, i + 1, j - 1);
    return max(LPSrecursivo(s, i + 1, j), LPSrecursivo(s, i, j - 1));
}


int LPSdp(string alderecho, int largo){
    int DP[100][100];
    memset(DP, 0, sizeof(DP));

    for(int i = largo - 1; i >= 0; i--){
        DP[i][i] = 1;
        for(int j = i + 1; j < largo; j++){
            if(alderecho[i] == alderecho[j])
                DP[i][j] = DP[i + 1][j - 1] + 2;
            else
                DP[i][j] = max(DP[i + 1][j], DP[i][j - 1]);
        }
    }

    return DP[0][largo - 1];
}


int main(){
    sync;
    string alderecho = "PAAAAAAP";

    cout<<LPSrecursivo(alderecho, 0, alderecho.length() - 1)<<endl;
    cout<<LPSdp(alderecho, alderecho.length())<<endl;

    return 0;
}