#include <stdio.h>
#include <time.h>
#include <Windows.h>

#define numThreads 12
/*

for the posix code
PS D:\programacion\Competitive-Programming\todas las frutas> cd "d:\programacion\Competitive-Programming\todas las frutas\" ; if ($?) { gcc -std=c11 -mavx posix.c -o posix} ; if ($?) { .\posix }


*/
long cantidadIntervalos = 1000000000;
double baseIntervalo;
double acum = 0;

clock_t start, end;

CRITICAL_SECTION mutex;

DWORD WINAPI routine(LPVOID pArg) {
	double* nThread = (double*)pArg;
	double x = (*nThread) * (cantidadIntervalos / numThreads) * baseIntervalo;
	double fdx;
	double acumuladoLocal = 0;
	for (long i = 0; i < cantidadIntervalos / numThreads; i++){
		fdx = 4 / (1 + x * x);
		acumuladoLocal += (fdx * baseIntervalo);
		x += baseIntervalo;
	}
	EnterCriticalSection(&mutex);
	acum += acumuladoLocal;
	LeaveCriticalSection(&mutex);
	return 0;

}

void main(){
	long i;
	HANDLE hThread[numThreads];
	double tNum[numThreads];
	baseIntervalo = 1.0 / cantidadIntervalos;
	start = clock();
	InitializeCriticalSection(&mutex);
	for(i = 0; i < numThreads; i++){
		tNum[i] = i;
		hThread[i] = CreateThread(NULL, 0, routine, &tNum[i], 0, NULL);
	}
	WaitForMultipleObjects(numThreads, hThread, TRUE, INFINITE);
	DeleteCriticalSection(&mutex);
	end = clock();
	printf("Resultado = %20.18lf (%ld)\n", acum, end - start);
}
