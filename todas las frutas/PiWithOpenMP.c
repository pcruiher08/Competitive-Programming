
/*

for the opempcode
PS D:\programacion\Competitive-Programming\todas las frutas> cd "d:\programacion\Competitive-Programming\todas las frutas\" ; if ($?) { gcc -std=c11 -fopenmp PiWithOpenMP.c -o PiWithOpenMP } ; if ($?) { .\PiWithOpenMP }


*/

#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <windows.h>

long cantidadIntervalos = 1000000000;
double baseIntervalo;
double fdx;
double acum, acum2 = 0;
clock_t start, end;

void main(){
	double x;
	long i;
	int threadnum = 12;
	baseIntervalo = 1.0 / cantidadIntervalos;
	start = clock();
	omp_set_num_threads(threadnum);
	#pragma omp parallel
	{
		for (i = 0, x = baseIntervalo * cantidadIntervalos / threadnum * omp_get_thread_num(); i < cantidadIntervalos / threadnum; i++){
			fdx = 4 / (1 + x * x);
			acum = acum + (fdx * baseIntervalo);
			x = x + baseIntervalo;
		}
		Sleep(1);
		acum2 += acum;
		printf("%d\n", omp_get_thread_num());
		Sleep(1);
	}
	end = clock();
	printf("Resultado = %20.18lf (%ld)\n", acum2, end - start);
}
