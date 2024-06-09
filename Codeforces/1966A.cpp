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
    int n, k; cin>>n>>k;
    int bucket[102];
    memset(bucket, 0, sizeof(bucket));
    for(int i = 0; i < n; i++){
        int lec; cin>>lec;
        bucket[lec]++;
    }
    int index_mayor = 0;
    int index_segundo = 0;
    bool flag = true;
    while(flag){
        
        flag = false;
        index_mayor = 0;
        index_segundo = 0;
        for(int i = 0; i < 101; i++){     
            if(bucket[i] >= k)      
                flag = true;
        
            if(bucket[i] > bucket[index_mayor]){
                index_mayor = i;
            }

        }
        if(flag){
            for(int i = 0; i < 101; i++){     
                if(bucket[i] > bucket[index_segundo] && i != index_mayor){
                    index_segundo = i;
                }
            }

            

            if(bucket[index_mayor] - 1 > bucket[index_segundo] + (k - 1)){
                index_segundo = index_mayor;
            }

            if(bucket[index_mayor] >= k){
                bucket[index_mayor] -= (k);
                bucket[index_segundo] += (k - 1);
            }
        }
     

    }
    int res = 0;
    for(int i = 0; i < 101; i++){
        res+=bucket[i];
    }
    cout<<res<<endl;
}

return 0;
}