#include <stdio.h>

void main(){
    uint32_t *ptr=(uint32_t*)1000;
    ptr = ptr +3;
    printf("%u",ptr);
}