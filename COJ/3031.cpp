#include <iostream>

int main(){
    long long numerador;
    long long denominador;
    long long enteroDeFraccion;
    scanf("%lld", &numerador);
    scanf("%lld",&denominador);
    while(numerador != 0 && denominador != 0){
        long long complemento;
        enteroDeFraccion = numerador/denominador;
        complemento = enteroDeFraccion * denominador;
        numerador = numerador - complemento;
        printf("");
        printf("%llu", enteroDeFraccion);
        printf(" ");
        printf("%llu", numerador);
        printf(" / ");
        printf("%llu\n", denominador);
        scanf("%lld",&numerador);
        scanf("%lld",&denominador);
    }
}