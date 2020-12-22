mod = 1000000007
def mod_exp(b,e,mod):
    r = 1
    while e > 0:
        if (e&1) == 1:
            r = (r*b)%mod
        b = (b*b)%mod
        e >>= 1

    return r

# Using Fermat's little theorem to compute nCk mod p
# Note: p must be prime and k < p
def fermat_binom(n,k,p):
    if k > n:
        return 0

    # calculate numerator
    num = 1
    for i in range(n,n-k,-1):
        num = (num*i)%p

    # calculate denominator
    denom = 1
    for i in range(1,k+1):
        denom = (denom*i)%p

    # numerator * denominator^(p-2) (mod p)
    return (num * mod_exp(denom,p-2,p))%p

# Using Fermat's little theorem to pre-compute factorials and inverses
# Note: only works when p is prime and k < p
def fermat_compute(n,p):
    facts = [0]*n
    invfacts = [0]*n

    facts[0] = 1
    invfacts[0] = 1
    for i in range(1,n):
        # calculate factorial and corresponding inverse
        facts[i] = (facts[i-1]*i)%p
        invfacts[i] = mod_exp(facts[i],p-2,p)

    return facts, invfacts

# Compute binomial coefficient from given pre-computed factorials and inverses
def binom_pre_computed(facts, invfacts, n, k, p):
    # n! / (k!^(p-2) * (n-k)!^(p-2)) (mod p)
    return (facts[n] * ((invfacts[k]*invfacts[n-k] % p))) % p


n = int(input())
facts, invfacts = fermat_compute(100001,mod)
while(n):
    A,B,C,K,c = map(int,input().split())
    producto = binom_pre_computed(facts, invfacts, C,c,mod)
    sumas = 0
    resta = K - c

    #considerar el caso donde A+B+C < K, regresar 0
    #considerar el caso donde A+B < K - c, regresar 0
    for i in range(1, resta - 1):
        if(i <= A and resta - i <= B):
            izq = i
            der = resta - i
            #cout<<nCk(A,izq,mod) * nCk(B,der,mod)
            if(der + izq == resta):
                sumas += (binom_pre_computed(facts, invfacts, A,izq,mod) * binom_pre_computed(facts, invfacts, B,der,mod))%mod

    print( ((((sumas%mod) * (producto%mod))%mod)+mod)%mod)

   
    n-=1