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

bool isAbundant(int n){
    int sum=0; 
    FOR(i,1,sqrt(n)+1,1){ 
        if(n%i==0){ 
            if(n/i==i){
                sum+=i; 
            }else{ 
                sum+=i; 
                sum+=n/i; 
            } 
        } 
    } 
    sum-=n; 
    return sum > n; 
} 
int main(){
sync;
    vi abundants;
    FOR(i,0,28123,1){
        if(isAbundant(i) && i!=2 && i!=6){
            abundants.pb(i);
        }
    } 

    set<int> sums;
    FOR(i,0,abundants.size(),1){
        FOR(j,0,abundants.size(),1){
            sums.insert(abundants[i]+abundants[j]);
        }
    }

    set<int>::iterator it = sums.begin();
    set<int>::reverse_iterator lastElement = sums.rbegin();
    ull sumaTotal = 0;
    ull gaussMayor = (*lastElement) * (*lastElement + 1) * 0.5;
    FOR(i,0,sums.size(),1){sumaTotal+=*it; it++;}
    cout<<gaussMayor - sumaTotal;
    return 0; 
}