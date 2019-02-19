#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	reverse(a.begin(), a.end());
	int rem = 0;
	for (int i = 0; i < n; ++i) {
		if (rem - a[i] < 0) {
			if (m == 0) {
				cout << i << endl;
				return 0;
			} else {
				--m;
				rem = k - a[i];
			}
		} else {
			rem -= a[i];
		}
	}
	
	cout << n << endl;
	
	return 0;
}

/*
5 1 4
4 2 3 4 1
*/
/*
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	reverse(a.begin(), a.end());
	int rem = 0;
	for (int i = 0; i < n; ++i) {
		if (rem - a[i] < 0) {
			if (m == 0) {
				cout << i << endl;
				return 0;
			} else {
				--m;
				rem = k - a[i];
			}
		} else {
			rem -= a[i];
		}
	}
	
	cout << n << endl;
	
	return 0;
}
*/