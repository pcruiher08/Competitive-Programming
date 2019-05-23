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
ull actualSetSize = 0;
set<int> yaRevisados;
bool firstIsCorrect = false;
bool secondIsCorrect = false;
FOR(i,1,10000,1){
    ull actualRes = sumaDeDivisores(i);
    yaRevisados.insert(i);
    if(yaRevisados.size() > actualSetSize) firstIsCorrect = true, actualSetSize++;
    yaRevisados.insert(actualRes);
    if(yaRevisados.size() > actualSetSize) secondIsCorrect = true, actualSetSize++;
    ull newRes = sumaDeDivisores(actualRes);
    if(newRes == i && actualRes != newRes && secondIsCorrect && firstIsCorrect) suma+=(actualRes+newRes);
}
cout<<suma;

return 0;
}
