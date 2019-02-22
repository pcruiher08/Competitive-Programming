#include<stdio.h>
int main(){

int n,suma=0;

scanf("%d",&n);

if(n>0){
	suma = n*(n+1)/2;
}
else if(n<=1){
	for(int i = 1; i >= n; i--){	
		suma+=i;
	}
}

printf("%d\n",suma);

}