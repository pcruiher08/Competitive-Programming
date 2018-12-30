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

//no terminado
ull sumaDeDivisores(ull n){ 
    ull suma = 0; 
    for(ull i=2; i<=sqrt(n); i++){ 
        if(n%i==0){
            if(i==(n/i)){
                suma += i; 
            }else{
                suma+=(i+n/i); 
            }
        } 
    } 
    return (suma + 1); 
} 

int main(){
sync;

ull suma = 0; 

FOR(i,1,10000,1){
    if(sumaDeDivisores(sumaDeDivisores(i))==i){
        suma+=i;
    }
}
cout<<suma;

return 0;
}
