#include <stdio.h>

int main(){

int num1;
int num2;
int num3;

    printf("Give me the first operand: \n");
    scanf("%d",&num1);
    printf("Give me the second operand: \n");
    scanf("%d",&num2);
    num3 = num1 + num2;
    printf("The result of %d and %d is : %d\n",num1,num2,num3);
}

