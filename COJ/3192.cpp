#include<stdio.h>
#include <iostream>
#include <cstring>
//using namespace std;

//para n < p y r < p.
int nCrModpdp(int n, int r, int p)
{
    int C[r+1];
    std::memset(C, 0, sizeof(C));
    
    C[0] = 1;//PASCAL
    for (int i = 1; i <= n; i++){
        for (int j = std::min(i, r); j > 0; j--)
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
//TEOREMA DE LUCAS
//C(N, K) % MOD = (C(n0, k0) * C(n1, k1) * … * C(nm-1, km-1)) % MOD
int nCrLucas(int n, int r, int p){
    if (r==0)
        return 1;
    int ni = n%p;
    int ri = r%p;
    return (nCrLucas(n/p, r/p, p) * nCrModpdp(ni, ri, p)) % p;
}

int main(){
    unsigned n,k,t;
    scanf("%u",&t);
    while(t--){
        scanf("%u%u",&n,&k);
        printf("%u\n", nCrLucas(n+k-1,k-1,1000000007));
    }
}