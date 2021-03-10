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