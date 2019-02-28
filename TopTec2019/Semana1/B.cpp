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
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

string sum(string a, string b) {
    string suma, lo;
    
    if(a.length() >= b.length()){
        suma = a;
    }else{
        suma = b;
    }

    if(suma == a){
        lo = b; 
    }else{
        lo = a;
    }

    int r = suma.length()-1;
    int carry = 0;
    for (int i = lo.length()-1; i>= 0; i--) {
        int x = lo[i] - '0';
        int y = suma[r] - '0';
        int res = x + y + carry;
        suma[r -- ] = (res % 2 + '0');
        carry = res / 2;
    }
    while (r >= 0 && carry) {
        int x = suma[r] - '0';
        int res = x + carry;
        suma[r--] = (res % 2 + '0');
        carry = res / 2;
    }
    if (carry) suma = '1' + suma;

    return suma;
}


int main(){
sync;
int n; cin>>n; 

FOR(i,0,n,1){
    string bin1, bin2;
    cin>>bin1>>bin2;
    cout<<i+1<<" "<<sum(bin1,bin2)<<endl;
}


return 0;
}