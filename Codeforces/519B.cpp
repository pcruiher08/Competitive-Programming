#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
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
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){
    sync;
    int len; cin>>len; 
    int arr1[len];
    int arr2[len];
    int arr3[len];


    set<int> magicSet;
    int auxArr3;
    FOR(i,0,len,1)cin>>arr1[i];
    FOR(i,0,len-1,1)cin>>arr2[i];
    FOR(i,0,len-2,1)cin>>arr3[i];

    int magicSetLen = len-2;
    int res1, res2;
    sort(arr1, arr1 + len);
    sort(arr2, arr2 + len - 1);
    sort(arr3, arr3 + len - 2);
    
    bool found = 0;
    for (int i = 0; i < len - 2; i++) {
        if (arr2[i] != arr3[i]) {
            res2 = arr2[i];
            found = 1;
            break;
        }
    }

    if (!found) res2 = arr2[len - 2];
    
    found = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr1[i] != arr2[i]) {
            res1 = arr1[i];
            found = 1;
            break;
        }
    }

    if (!found) res1 = arr1[len - 1];

    cout<<res1<<endl<<res2<<endl;









return 0;
}