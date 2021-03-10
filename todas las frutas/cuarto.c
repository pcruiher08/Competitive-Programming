#include <stdio.h>

int main(){

    int num1;
    int num2;
    int num3;
    int num4;
    char operation = ' ';



    printf("Give me the first operand: \n");
    scanf("%d",&num1);
    printf("Give me the operation to be performed (+, -, *, /): \n");
    scanf(" %c",&operation);
    printf("Give me the second operand: \n");
    scanf("%d",&num2);
    printf("Give me the third operand: \n");
    scanf("%d",&num3);
    if(operation == '+')num4 = num1 + num2 + num3;
    if(operation == '-')num4 = num1 - num2 - num3;
    if(operation == '*')num4 = num1 * num2 * num3;
    if(operation == '/')num4 = num1 / num2 / num3;
    printf("The result of %d %c %d %c %d is : %d\n",num1,operation,num2,operation,num3,num4);
}

