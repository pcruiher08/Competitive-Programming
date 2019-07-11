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

void fizzBuzz(int n){
    if(n%3==0&&n%5==0){
        cout<<"FizzBuzz"<<endl;
        return;
    }
    if(n%3==0){
        cout<<"Fizz"<<endl;
        return;
    }
    if(n%5==0){
        cout<<"Buzz"<<endl;
        return;
    }
    cout<<n<<endl;
}

int main(){
    FOR(i,1,1001,1)fizzBuzz(i);
}