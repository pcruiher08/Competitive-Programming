#include <iostream>

using namespace std;

int main()
{
	int t =0, i =1;
	cin>> t;
	while(t--)
    {
        int arreglo[10];
		int t=10,arriba=101,abajo=0, sumatoria=0;
		for(int i =0; i < t; i++){
			cin>> arreglo[i];
			sumatoria+=arreglo[i];
            if(arreglo[i] > abajo) abajo = arreglo[i];
			if(arreglo[i] < arriba) arriba = arreglo[i];
		}
		sumatoria = sumatoria - (arriba+abajo);
		cout<<i++<<" "<<sumatoria<<endl;
	}
	return 0;
}