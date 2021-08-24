#include <omp.h>
#include <stdio.h>
int var = 10;

void main()
{
    printf("Initial value (%d), Var=%d\n\n", omp_get_thread_num(), var);
    #pragma omp parallel num_threads (2)
    {
        var *= (omp_get_thread_num() + 1);  //Potential race condition.
        printf("Thread (%d), Var=%d\n\n", omp_get_thread_num(), var);
    }
    var += 1000;
    #pragma omp parallel num_threads (2)
    {
        printf("Thread (%d), Var=%d\n\n", omp_get_thread_num(), var);
    }
}
