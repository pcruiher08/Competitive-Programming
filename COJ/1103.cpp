#include <stdio.h>
#define MXCOINS 7500
using namespace std;
int c[] ={1, 5, 10, 25, 50};
int mem[MXCOINS][6];
int change(int mon, int i){
	if(mon == 0){
		return 1;
	}
	if(i == 5){
		return 0;
	}
	if(mem[mon][i] != -1){
		return mem[mon][i];
	}
	if(c[i] <= mon ){
		mem[mon - c[i]][i] = change(mon - c[i],i);
		mem[mon][i+1] = change(mon,i+1);
		return mem[mon - c[i]][i] + mem[mon][i+1];
	}
	else {
		mem[mon][i+1] = change(mon,i+1);
		return mem[mon][i+1];
	}
}

int main(){
	int moneyyyy;
	for(int i = 0; i < MXCOINS; i++){
		for(int j = 0; j < 5; j++){
			mem[i][j] = -1;
		}	
	}
	while(scanf("%d",&moneyyyy) != EOF){

		printf("%d\n",change(moneyyyy,0));
	}
	return 0;
}