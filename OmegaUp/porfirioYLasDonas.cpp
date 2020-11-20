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
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

bool sePuede(int x, int a, int b){
    /*
    if(x%a==0){
        return true;
    }
    if(x%b==0){
        return true;
    }
    
    if(((x%a)%b==0)||(x%b==0)){
        return true;
    }
    if(((x%b)%a==0)||(x%a==0)){
        return true;
    }
    return false;
    */
   if(x%a==0) return true;
   if(x%b==0) return true;
   while(x>=0){
       x-=a;
       if(x==0) return true;
       if(x%b==0) return true;
   }
   return false;
}

int main(){
    sync;
    int n,a,b;
    cin>>n>>a>>b;
    int x;
    while(n--){
        cin>>x;
        cout<<(sePuede(x,a,b)?"Si":"No")<<endl;
    } 
    return 0;
}