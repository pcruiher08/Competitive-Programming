/*
#include <omp.h>
#include <stdio.h>
#include <windows.h>

int main() {
   int sharedVar = 6;
   #pragma omp parallel num_threads(10)                   
   {
      int privateVar = omp_get_thread_num(); //This data is mine!
      sharedVar = omp_get_thread_num(); //I´ll leave my mark!
      //Add here a pause.
      printf("Thread (%d), privateVar = %d, sharedVar= %d \n", omp_get_thread_num(), privateVar, sharedVar);
   }
}
*/

#include <stdio.h>
#include <omp.h>
int main() {
    int rT = 8000;   //Requested Threads
    int aT = 0;   //Actual Threads

    do {
        rT += 10;
        omp_set_num_threads(rT);
#pragma omp parallel
        {
            if (omp_get_thread_num() == 0) {
                aT = omp_get_num_threads();
                printf("Master Control Program gave me %d threads. He's a nice program.\n", aT);
            }
            int a = 50 + 100; //Just some work...
        }
    } while (rT == aT);

    printf("\nI take it back! Master Control Program gave me %d thread. He's EVIL!\n", aT);
    return 0;
}
