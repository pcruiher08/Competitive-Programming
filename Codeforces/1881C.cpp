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
int t; cin>>t;
while(t--){
    int n; cin>>n;
    int cuenta = 0;
    int mat1[n][n], mat2[n][n];
    int mat3[n][n];
    
    FOR(i,0,n,1){
        FOR(j,0,n,1){
            char lec; cin>>lec;
            mat1[i][j] = lec - 'a';
            mat2[j][n - 1 - i] = mat1[i][j];
        }
    }

    int res = 0;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            char cell1 = mat1[i][j];
            char cell2 = mat1[j][n - 1 - i];
            char cell3 = mat1[n - 1 - j][i];
            char cell4 = mat1[n - 1 - i][n - 1 - j];

            // Calculate the number of operations needed for each set of cells
            vector<int> diffs = {abs(cell1 - cell2), abs(cell1 - cell3), abs(cell1 - cell4)};
            int minDiff = *min_element(diffs.begin(), diffs.end());
            res += minDiff;
        }
    }

    
    cout<<"RESSS : "<<res<<endl;

}
return 0;
}