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

void primeFactors(int n, map<int, int> &m){  

    while (n%2 == 0){  
        m[2]++;
        //printf("%d ", 2);  
        n = n/2;  
    }  
     
    for (int i = 3; i <= sqrt(n); i = i+2){  
        while (n%i == 0){  
            //printf("%d ", i);  
            m[i]++;
            n = n/i;  
        }  
    }  
     
    if(n > 2){ 
        //printf("%d ", n);  
        m[n]++;
    }
}  

int main(){
sync;

int t; cin>>t; 
while(t--){
    int n; cin>>n;
    map<int, int> m;

    for(int i = 0; i<n; i++){
        int x; cin>>x;
        primeFactors(x,m);
    }
    //cout<<"prime factors:"<<endl;
    bool flag = true;
    for(auto a : m){
        if(a.second % n != 0){
            flag = false;
        }
        //cout<<a.first << " "<< a.second<<endl;
    }
    //cout<<endl<<endl<<"////////"<<endl;
    cout<<(flag?"YES":"NO")<<endl;
}

return 0;
}