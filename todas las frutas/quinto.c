#include <stdio.h>

int main(){
    int x;
    printf("Give me the x: \n");
    scanf("%d",&x);
    printf("The result of 6*%d^2+9*%d+2 is : %d\n",x,x,6*x*x+9*x+2);
}

