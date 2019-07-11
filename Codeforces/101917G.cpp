#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <cstring>

using namespace std;


long long gcd (long long n1, long long n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}


long long sum2(long long a, long long b){
    int aux = gcd(a,b);
    return (a / aux) * (b / aux) * aux;
}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,a,b,c,d,e,f, den, num, gc;
    char aux;
    cin >> n;
    while(n--){
       cin >>  a >> aux >> b >> c >> aux >> d >> e >> aux >> f;
       den = sum2(b,d);
       den = sum2(den,f);

       num = a * (den / b) + c * (den / d) + e * (den / f);

       gc = gcd(num,den);
       cout << (num / gc) << "/" << (den / gc) << endl;

    }

	return 0;
}