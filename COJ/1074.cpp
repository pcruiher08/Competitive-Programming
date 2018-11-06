#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

int x[13], N, mit;

bool gutgut(int columna, int fila)
{
    for(int anterior = 1; anterior <= columna - 1; anterior++)
        if(x[anterior] == fila || (abs(x[anterior] - fila) == abs(anterior - columna)))
            return false;
    return true;
}

void Queens(int columna)
{
    for(int fila = 1; fila <= N; fila++){
        if(gutgut(columna, fila)){
            x[columna] = fila;
            if(columna == N){
                printf("%d : ", ++mit);
                for(int i = 1; i <= N; i++)
                    printf("%d ", x[i]);
                printf("\n");
            }
            else {
                Queens(columna + 1);
            }
        }
    }
}

int main()
{
    while(scanf("%d", &N) != EOF)
    {
        memset(x, 0, sizeof(x));
        mit = 0;
        Queens(1);
        if(mit == 0)
            printf("No Solution.\n");
    }
    return 0;
}