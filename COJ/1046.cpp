#include<stdio.h>

int main(){
    
    int n;
    int a;
    int b;
    
    scanf("%d",&n);
    long long int suma;
    while(n--){
        suma = 0;
        scanf("%d%d",&a,&b);
        for(long i=a; i<=b; i++){
            suma+=i*(i+1)*(i+2);
        }
        printf("%lld\n",suma%100);
    }
    
}