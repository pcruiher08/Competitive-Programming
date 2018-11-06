#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
long long int tam;
bitset <10000010> bs;
vi primes;

void sieve(long long int upperbound)
{
    tam = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i <= tam; i++){
        if(bs[i]){
            for(long long int j = i*i; j <= tam; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}

vi primeFactors(int N)
{
    vi factors;
    int PF_idx = 0, PF = primes[PF_idx];

    while(N != 1 && (PF * PF) <= N){
        while(N % PF == 0){
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[++PF_idx];
    }
    if(N != 1) factors.push_back(N);
    return factors;
}

int main()
{
    int N, m, aux, cow, maxPF = -1;
	vi factores;

	sieve(100000);
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
    {
        scanf("%d", &m);
        if(m == 1)
            aux = 0;
        else {
            factores = primeFactors(m);
            int l = factores.size();
            aux = factores[l - 1];
        }
        if(maxPF < aux){
            cow = m;
            maxPF = aux;
        }
        factores.clear();
    }
    printf("%d\n", cow);
	return 0;
}