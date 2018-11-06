#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define FORI(s,n) for(int i = s; i < n; i++)
#define FORIp(s,n,p) for(int i=s, j=p; i<n; i++, j++)
#define pb push_back
int main() {
    int n,lec;
    cin >> n;
    vector<int> set;
    FORI(0,2*n) static_cast<void>(cin>>lec), set.pb(lec);
    sort(set.begin(), set.end());
    long long ans = 1ll*(set[n-1]-set[0])*(set[2*n-1]-set[n]);
    FORIp(1,n,n) ans = min(ans, 1ll*(set[2*n-1]-set[0])*(set[j]-set[i]));
    cout << ans << endl;
    /*
     4
     4 1 3 2 3 2 1 3
     2
     */
}