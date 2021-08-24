#include <stdio.h>
#include <time.h>
#include <Windows.h>

#define numThreads 2

long cantidadIntervalos = 1000000000;
double baseIntervalo;
double acum = 0;

clock_t start, end;

CRITICAL_SECTION mutex;

DWORD WINAPI routine(LPVOID pArg) {
	double* nThread = (double*)pArg;
	double x = (*nThread) * (cantidadIntervalos / numThreads) * baseIntervalo;
	double fdx;
	double local_acum = 0;
	for (long i = 0; i < cantidadIntervalos / numThreads; i++)
	{
		fdx = 4 / (1 + x * x);
		local_acum += (fdx * baseIntervalo);
		x += baseIntervalo;
	}

	EnterCriticalSection(&mutex);
	acum += local_acum;
	LeaveCriticalSection(&mutex);

	return 0;

}

void main()
{
	long i;
	HANDLE hThread[numThreads];
	double tNum[numThreads];

	baseIntervalo = 1.0 / cantidadIntervalos;

	start = clock();

	InitializeCriticalSection(&mutex);
	for (i = 0; i < numThreads; i++)
	{
		tNum[i] = i;
		hThread[i] = CreateThread(NULL, 0, routine, &tNum[i], 0, NULL);
	}
	WaitForMultipleObjects(numThreads, hThread, TRUE, INFINITE);
	DeleteCriticalSection(&mutex);
	end = clock();
	printf("Resultado = %20.18lf (%ld)\n", acum, end - start);
}


/*
#include <stdio.h>
#include <time.h>

long cantidadIntervalos = 1000000000;
double baseIntervalo;
double fdx;
double acum = 0;
clock_t start, end;

void main() {

	double x;
	long i;

	baseIntervalo = 1.0 / cantidadIntervalos;
	start = clock();

	for (i = 0, x = 0.0; i < cantidadIntervalos; i++) {

		fdx = 4 / (1 + x * x);
		acum = acum + (fdx * baseIntervalo);
		x = x + baseIntervalo;

	}

	end = clock();
	printf("Resultado = %20.18lf (%ld)\n", acum, end - start);

}

*/

/*
#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <windows.h>

long cantidadIntervalos = 1000000000;
double baseIntervalo;
double fdx;
double acum, acum2 = 0;
clock_t start, end;

void main() {

	double x;
	long i;

	int threadnum = 8;

	baseIntervalo = 1.0 / cantidadIntervalos;
	start = clock();

	omp_set_num_threads(threadnum);
	#pragma omp parallel
	{
		for (i = 0, x = baseIntervalo * cantidadIntervalos / threadnum * omp_get_thread_num(); i < cantidadIntervalos / threadnum; i++)
		{
			fdx = 4 / (1 + x * x);
			acum = acum + (fdx * baseIntervalo);
			x = x + baseIntervalo;
		}
		Sleep(1);
		acum2 += acum;
		printf("acum=%f, %d\n", acum, omp_get_thread_num());
		Sleep(1);
	}

	end = clock();
	printf("Resultado = %20.18lf (%ld)\n", acum2, end - start);
}*/