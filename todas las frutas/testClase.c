#include <omp.h>
#include <stdio.h>
#include <Windows.h>

void main() {

    #pragma omp parallel num_threads(8) 
    {
        #pragma omp single
        printf("Total threads available (%d): %d \n\n", omp_get_thread_num(), omp_get_num_threads());
        #pragma omp sections nowait
     {
         #pragma omp section
         {
             Sleep(10);
             printf("Thread (%d), Hello from section 1\n\n", omp_get_thread_num());
         }
         #pragma omp section
         {
             Sleep(1000);
             printf("Thread (%d), Hello from section 2\n\n", omp_get_thread_num());
         }
         #pragma omp section
         {
             Sleep(1000);
             printf("Thread (%d), Hello from section 3\n\n", omp_get_thread_num());
         }
         #pragma omp section
         {
              Sleep(1000);
              printf("Thread (%d), Hello from section 4\n\n", omp_get_thread_num());
         }
     }
    }
    printf("Thread (%d) outside section\n", omp_get_thread_num());
}
