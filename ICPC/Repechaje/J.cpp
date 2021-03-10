#include <iostream>
#include <cmath>

using namespace std;



long long gcd(long long a, long long b){
   return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b){
   return (a * b) / gcd(a, b);
}

int main() {
	long long cases;
	cin >> cases;
	for(long long i = 0; i < cases; i++) {
		long long c, n1, n2, dist;
		cin >> c >> n1 >> n2 >> dist;
		long long turnFreqA = 12 / gcd(12, n1);
		long long turnFreqB = 12 / gcd(12, n2);
		long long turnFreq = lcm(turnFreqA, turnFreqB);
		cerr << turnFreqA << " " << turnFreqB << " " << turnFreq << endl;
		long long minTurns = 12 * dist / c;
		long long mult = ceil((float)minTurns / turnFreq);
		cout << turnFreq * mult << endl;
	}
}