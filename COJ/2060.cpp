#include <iostream>
int main(){
	int n, tr=0, cuenta=0, c=0;
	while(scanf("%d",&n)&&n!=-1){
    cuenta=0; 
    c=0;
		while(n--){
			scanf("%d",&tr);
			cuenta+=tr;
			if(!(cuenta%100))
				c++;
			tr=0;
		}
		printf ("%d\n",c);
	}
}