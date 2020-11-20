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

bool checkStraightLine(vector<vector<int>>& coordinates) {
    if (coordinates.size() <= 2) return true;
    int dx = coordinates[0][0] - coordinates[1][0];
    int dy = coordinates[0][1] - coordinates[1][1];
    for (int i = 2; i < coordinates.size(); ++ i) {
        int dx1 = coordinates[0][0] - coordinates[i][0];
        int dy1 = coordinates[0][1] - coordinates[i][1];            
        if (dx1 * dy != dy1 * dx) return false;
    }
    return true;
}

int main(){
sync;
vector<vector<int>> coordinates;
vector<int> nums;
int n; cin>>n;
FOR(i,0,n,1){
    int lee; cin>>lee;
    nums.pb(lee);
}
sort(nums.begin(),nums.end());
ull cuenta = 0;
do{

vector<vector<int> >coords;
FOR(i,0,n,2){
    vector<int> aux;
    aux.pb(nums[i]);
    aux.pb(nums[i+1]);
    coords.pb(aux);
}
//cout<<coords.size()<<endl;

if(checkStraightLine(coords)) cuenta++;

}while(next_permutation(nums.begin(),nums.end()));

cout<<cuenta<<endl;
return 0;
}