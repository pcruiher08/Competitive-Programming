#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	int x, y;
};

long long int gcd(long long int a, long long int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	Point pts[n];
	for(int i = 0; i < n; i++) {
		cin >> pts[i].x >> pts[i].y;
	}
	long double area = 0;
	for(int i = 0; i < n; i++) {
		long double current = (long double)pts[i].x * pts[(i + 1) % n].y - (long double)pts[(i + 1) % n].x * pts[i].y;
		area += current;
	}
	area = abs(area / 2);
	long long int edgePoints = 0;
	for(int i = 0; i < n; i++) {
		if(pts[i].x == pts[(i + 1) % n].x) {
			edgePoints += abs(pts[i].y - pts[(i + 1) % n].y) - 1;
		} else if (pts[i].y == pts[(i + 1) % n].y) {
			edgePoints += abs(pts[i].x - pts[(i + 1) % n].x) - 1;
		} else {
			edgePoints += gcd(abs(pts[i].x - pts[(i + 1) % n].x), abs(pts[i].y - pts[(i + 1) % n].y)) - 1;
		}
	}
	edgePoints += n;
	//cout << n << endl;
	long long int answer = (area - edgePoints/2 + 1);
	cout << answer << endl;
}
