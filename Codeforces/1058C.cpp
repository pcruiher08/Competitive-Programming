#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iomanip>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main() {
    sync;
    int n, sum = 0, cur;
    bool flag;
    string s;
    cin>>n>>s;
    FOR(i,0,n-1,1){
        sum += s[i]-'0';
        flag = false; cur = 0;
        FOR(j,i+1,n,1){
            cur += s[j]-'0';
            if(cur==sum){
                cur = 0;
                flag = true;
            }
            else if(cur > sum){
                flag = false;
                break;
            }
        }
        if(cur==0&&flag){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<< "NO"<<endl;
    return 0;
}