#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int p;
    cin>>p;
    while(p--){
        int n;
        cin>>n;
        int arr[n][n];
        //char arr1[n][n];
        string e;
        for(int i=0; i<n; i++){
            string e;
            cin>>e;
            for(int j=0; j<n; j++)
                if(e[j]=='.') arr[i][j]=1;
                else arr[i][j]=0;
        }
        /*
         for(int i=0; i<n; i++){
         for(int j=0; j<n; j++)
         cout<<arr[i][j];
         cout<<endl;
         }
         */
        int matrizMenor[n][n];
        for (int i = 0; i < n; i++) matrizMenor[0][i] = arr[0][i];
        for(int i=0; i<n; i++) matrizMenor[i][0] = arr[i][0];
        
        
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
                if(arr[i][j]==1)//!(b<a)?a:b
                    matrizMenor[i][j] = min(matrizMenor[i-1][j-1], min(matrizMenor[i][j-1], matrizMenor[i-1][j]))+1;
        //matrizMenor[i][j] = min(matrizMenor[i-1][j-1], !(matrizMenor[i-1][j]<matrizMenor[i][j-1])?matrizMenor[i][j-1]:matrizMenor[matrizMenor[i-1][j]+1;
                else matrizMenor[i][j] = 0;
        
        
        
        
        int cuadrito = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrizMenor[i][j] > cuadrito)
                    cuadrito = matrizMenor[i][j];
        
        cout<<cuadrito<<endl;
    }
}