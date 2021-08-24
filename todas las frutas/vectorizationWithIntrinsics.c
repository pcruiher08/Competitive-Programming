#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <intrin.h>

// Single Threaded Array Addition FLOATs
//Command
/*
please specify the file location when running this command
cd "d:\programacion\Competitive-Programming\todas las frutas\" ; if ($?) { gcc -std=c11 -mavx vectorizationWithIntrinsics.cc -std=c11 -mavx vectorizationWithIntrinsics.c -o vectorizationWithIntrinsics } ; if ($?) { .\vectorizationWithIntrinsics }
*/

int main() {
	int i;
	float* A = NULL;
	float* B = NULL;
	float* C = NULL;
	int result = 1;
	const int elements = 52428800;
	time_t start, end;

	//Array creation
	size_t datasize = sizeof(float) * elements;
	A = (float*)malloc(datasize);
	B = (float*)malloc(datasize);
	C = (float*)malloc(datasize);

	//Array initialization (Normally you would get this from a file)
	for (i = 0; i < elements; i++) {
		A[i] = (float) i;
		B[i] = (float) i;
	}

	start = clock();
	//This loop can be optimized using Intrinsics
	for (i = 0; i < elements; i++)
		C[i] = A[i] + B[i];

	//sse and avx
	/*
	__m128 newA, newB, newC;
	for (i = 0; i < elements / 4; i++){
		newA = _mm_loadu_ps(A + i*4);
		newB = _mm_loadu_ps(B + i*4);
		newC = _mm_add_ps(newA, newB);
		_mm_storeu_ps(C + i*4, newC);
	}
	*/

	/*
	__m256 newA, newB, newC;
	for (i = 0; i < elements / 8; i++){
		newA = _mm256_loadu_ps(A + i*8);
		newB = _mm256_loadu_ps(B + i*8);
		newC = _mm256_add_ps(newA, newB);
		_mm256_storeu_ps(C + i*8, newC);
	}
	*/
	end = clock();

	//Validation
	for (i = 0; i < elements; i++) {
		if (C[i] != i + i) {
			result = 0;
			break;
		}			
	}

	//Print first 10 results
	for (i = 0; i < 10; i++) {
		printf("C[%d]=%10.2lf\n", i, C[i]);
	}

	if (result) {
		printf("Results verified!!! (%ld)\n", (long)(end - start));
	}
	else {
		printf("Wrong results!!!\n");
	}

	//Memory deallocation
	free(A);
	free(B);
	free(C);

	return 0;
}