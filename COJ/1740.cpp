#include <cstdio>
#include <cstring>
//by Pablo C. Ruíz pcruiher08
//NIVEL DOS 

char S[2002];
bool segundosMat[2002][2002];
int primeros[2001];

int main()
{
	scanf("%s", &S[1]);

	int n = strlen(&S[1]);

	for (int i = 1 ; i <= n ; i++)
		segundosMat[i][i] = true;

	for (int i = 1 ; i < n ; i++)
		segundosMat[i][i + 1] = S[i] == S[i + 1];

	for (int j = 3 ; j <= n ; j++)
		for (int i = 1 ; i <= n - j + 1 ; i++) 
			segundosMat[i][i + j - 1] = segundosMat[i + 1][i + j - 2] && (S[i] == S[i + j - 1]);

	primeros[n] = 1;
	for (int i = n - 1 ; i >= 1 ; i--){
		primeros[i] = primeros[i + 1];
		for (int j = i ; j <= n ; j++)
			primeros[i] += segundosMat[i][j];
	}

	long long sol = 0;
	for (int i = 1 ; i < n ; i++)
		for (int j = i ; j < n ; j++)
			if (segundosMat[i][j])
				sol += primeros[j + 1];

	printf("%lld\n", sol);

	return 0;
}