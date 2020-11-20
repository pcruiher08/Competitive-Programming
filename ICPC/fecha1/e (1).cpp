#include <iostream>
#include <unordered_set>
#include <vector>

#define INF 9223372036854775807

using namespace std;

int atkinSieve(long long int* primes, long long int limit) {
    int index = 0;
    limit++;
    if(limit < 3) {
        return index;
    }
    primes[index] = 2;
    index++;
    if(limit < 4) {
        return index;
    }
    primes[index] = 3;
    index++;
    bool* sieve = new bool[limit];
    for(long long int i = 0; i < limit; i++) {
        sieve[i] = false;
    }
    for(long long int i = 1; i * i < limit; i++) {
        for(long long int j = 1; j * j < limit; j++) {
            long long int a = 4 * i * i + j * j;
            long long int b = 3 * i * i + j * j;
            long long int c = 3 * i * i - j * j;
            if(a <= limit && (a % 12 == 1 || a % 12 == 5)) {
                sieve[a] = !sieve[a];
            }
            if(b <= limit && b % 12 == 7) {
                sieve[b] = !sieve[b];
            }
            if(c <= limit && i > j && c % 12 == 11) {
                sieve[c] = !sieve[c];
            }
        }
    }
    for(long long int i = 5; i * i < limit; i++) {
        if(sieve[i]) {
            for(long long int j = i * i; j < limit; j += i * i) {
                sieve[j] = false;
            }
        }
    }
    for(long long int i = 5; i < limit; i++) {
        if(sieve[i]) {
            primes[index] = i;
            index++;
        }
    }
    return index;
}

vector<string> getPermutations(string s) {
	vector<string> outputs;
	if(s.size() == 0) {
		outputs.push_back("");
		return outputs;
	}
	for(int i = 0; i < s.size(); i++) {
		string a = s.substr(0, i);
		string b = s.substr(i + 1, s.size() - i - 1);
		vector<string> subpermutations = getPermutations(a + b);
		for(int j = 0; j < subpermutations.size(); j++) {
			outputs.push_back(s[i] + subpermutations[j]);
		}
	}
	return outputs;
}

int main() {
	long long int* primes = new long long int[78498];
	int numPrimes = atkinSieve(primes, 1000000);
	unordered_set<int> primeSet;
	for(int i = 0; i < numPrimes; i++) {
		primeSet.insert(primes[i]);
	}
	string input;
	cin >> input;
	vector<string> permutations = getPermutations(input);
	long long int product = INF;
	for(int i = 0; i < permutations.size(); i++) {
		for(int j = 1; j < input.size(); j++) {
			for(int k = 1; k < input.size(); k++) {
				if(j + k > permutations[i].size()) {
					continue;
				}
				string a = permutations[i].substr(0, j);
				string b = permutations[i].substr(j, k);
				string c = permutations[i].substr(j + k, permutations[i].size() - j - k);
				if(a.size() > 0 && b.size() > 0 && c.size() > 0) {
					if(a[0] == '0' || b[0] == '0' || c[0] == '0') {
						continue;
					}
					long long int x = stoll(a);
					long long int y = stoll(b);
					long long int z = stoll(c);
					if(primeSet.count(x) > 0 && primeSet.count(y) > 0 && primeSet.count(z) > 0) {
						product = min(product, x * y * z);
					}
				}
			}
		}
	}
	if(product == INF) {
		cout << "Bob lies" << endl;
	} else {
		cout << product << endl;
	}
}