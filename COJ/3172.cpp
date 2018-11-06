#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;


long long suma;
long long sumaDeProductos;
long long mod=1e5;
int main(){
    int n, e, p =2, ex=2;
    e=2;
    p=2;
    
    scanf("%d", &n);
    long long numeros[n];
    //vector <long long> numeros(n);
    long long poligono[n];
    
    for(int i=1;i<=n;i++){
        scanf("%lld", &numeros[i]);
        suma+=numeros[i];
    }
    
    sort(numeros+1, numeros+1+n);
    poligono[1]=numeros[1];
 
    int ed=n,j=n;
    for(int c=1;c<n; c++){
        if(p<=j) poligono[ex++]=numeros[j--];
        if(p<=j) poligono[ed--]=numeros[j--];
        if(p<=j) poligono[ex++]=numeros[p++];
        if(p<=j) poligono[ed--]=numeros[p++];
    }
    poligono[0]=poligono[n];
    poligono[n+1]=poligono[1];
    for(int i=1;i<n;i++){
        if(i>2)suma-=poligono[i-2];
        sumaDeProductos=(sumaDeProductos+poligono[i]*((suma-poligono[i])-poligono[i-1]-poligono[i+1]))%mod;
    }

    
    printf("%05lld\n", sumaDeProductos);
}
