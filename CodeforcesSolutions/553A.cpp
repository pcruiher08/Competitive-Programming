#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

long long fact[100001];

long long actual = 1;

long long fac(long long n){
    fact[0]=1;
    fact[1]=1;
    
    if(n>actual){
    for(long long i=actual; i<=n; i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    actual = n;
    }
    return fact[n];
}


long long inve(long long a){
    long long b = mod-2, ans = 1;
    while (b) {
        if (b&1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    long long colors;
    cin>>colors;
    long long nColors[100001];
    long long sum =0;
    
    for (long long i = 1; i <= colors; ++i) {
        cin >> nColors[i];
        sum += nColors[i];
    }
    
    long long cuenta = 1;
    long long cuentaRepetidos=0;
    //cuenta+=nColors[0];
    long long p = 0;
    
    for(long long i=colors; i>0; --i){
        sum--;
        p = (nColors[i]-1);
        cuentaRepetidos = (((fac(sum)*inve(fac(p)))%mod)*inve(fac(sum-p)))%mod;
        if(cuentaRepetidos)
            cuenta = (cuenta*cuentaRepetidos)%mod;
        sum-=p;
    }
    
    if(cuentaRepetidos==0) cuenta = 1;
    
    cout<<cuenta<<endl;
 
    
}