#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <intrin.h>

// Single Threaded Array Addition FLOATs
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
	/*
	A = (float*)malloc(datasize);
	B = (float*)malloc(datasize);
	C = (float*)malloc(datasize);
	*/
	
	A = (float*)_aligned_malloc(datasize, 16);
	B = (float*)_aligned_malloc(datasize, 16);
	C = (float*)_aligned_malloc(datasize, 16);

	//Array initialization (Normally you would get this from a file)
	for (i = 0; i < elements; i++) {
		A[i] = (float) i;
		B[i] = (float) i;
	}

	/*
	start = clock();
	//This loop can be optimized using Intrinsics
	for (i = 0; i < elements; i++)
		C[i] = A[i] + B[i];
	end = clock();
	*/

	//SSE
	/*
	__m128 arrA, arrB, add;

	start = clock();

	for (i = 0; i < (elements / 4); i++) {
		arrA = _mm_load_ps(A + i * 4);
		arrB = _mm_load_ps(B + i * 4);
		add = _mm_add_ps(arrA, arrB);
		_mm_store_ps(C + i * 4, add);
	}
	end = clock();
	*/

	//AVX
	
	__m256 arrA, arrB, add;

	start = clock();

	for (i = 0; i < (elements / 8); i++) {
		arrA = _mm256_load_ps(A + i * 8);
		arrB = _mm256_load_ps(B + i * 8);
		add = _mm256_add_ps(arrA, arrB);
		_mm256_store_ps(C + i * 8, add);
	}
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
	/*
	free(A);
	free(B);
	free(C);
	*/

	_aligned_free(A);
	_aligned_free(B);
	_aligned_free(C);

	return 0;
}