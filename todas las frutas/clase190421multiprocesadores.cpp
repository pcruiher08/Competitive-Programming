#include <stdio.h>
#include <omp.h>

int cuenta(int &x){
    return ++x;
}

int main(){
    int c = 0;

    omp_set_num_threads(24);
    #pragma omp parallel
    {
        printf("%d\n",omp_get_thread_num());

    }
    
}