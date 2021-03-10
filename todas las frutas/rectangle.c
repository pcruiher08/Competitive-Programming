#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    int largo = 0, alto = 0;

    if(!strcmp(argv[1], "-a")){
        //area
        printf("area = %d units", (int)atoi(argv[3]) * (int)atoi(argv[5]));
    }else{
        //perimetro
        printf("perimeter = %d units", 2 * (int)atoi(argv[3]) + 2 * (int)atoi(argv[5]));
    }

    return 0;
}