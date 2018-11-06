#include <cstdio>
#include <algorithm>

using namespace std;

#define maxNumber 10010

int sge[maxNumber], v[maxNumber];
int T, N;

int main(){
	for (int i = 1; i < maxNumber; i++){
		for (int k = 1; k <= 3; k++)
			for (int j = 0; j+k <= i && j <= i-j-k; j++)
				v[sge[j] ^ sge[i-j-k]] = i;

		for (int k = 0;; k++)
			if (v[k] != i){
				sge[i] = k;
				break;
			}
	}

	scanf("%d", &T);

	while (T--){
		scanf("%d", &N);

		int x = 0, y;
		while (N--){
			scanf("%d", &y);
			x ^= sge[y];
		}

		printf("%s\n", x ? "MIRKO" : "SLAVKO");
	}
}