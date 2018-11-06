
#include <stdio.h>
#include <string.h>

int main(){
    int agregados;
    int i;
    int distEntDat;
    int largo;
    int cifras;
    char num[99];
    char ent[99];
    char arr[3];
    char comparacion[30];
    
    for (i=0; i<99; i++){
        ent[i]='0';
        num[i]='0';
    }
    scanf("%s",num);
    distEntDat=strlen(num); //string length
    
    if(distEntDat%3 ==0) agregados=0; //modulo 3 congruente a 0
    
    if(distEntDat%3 ==1){ //checar //modulo 3 congruente a 1
        ent[0] = '0';
        ent[1] = '0';
        agregados = 2;
    }
    
    if(distEntDat %3 ==2){ //checar // modulo 3 congruente 2
        ent[0]='0';
        agregados=1;
    }
    
    for (i=0; i< distEntDat; i ++)
        ent[i+agregados]=num[i];
    
    distEntDat = distEntDat + agregados;
    
    largo = distEntDat-1;
    
    for (cifras =(distEntDat/3)-1; cifras >=0 ; cifras --){
        
        arr[2] = ent[largo];
        arr[1] = ent[largo-1];
        arr[0] = ent[largo-2];
        //checar los numeros en binario -> decimal
        if (arr[0] == '0' && arr[1]=='0' && arr[2]=='0') /*000*/ comparacion[cifras] = '0';
        if (arr[0] == '0' && arr[1]=='0' && arr[2]=='1') /*001*/ comparacion[cifras] = '1';
        if (arr[0] == '0' && arr[1]=='1' && arr[2]=='0') /*010*/ comparacion[cifras] = '2';
        if (arr[0] == '0' && arr[1]=='1' && arr[2]=='1') /*011*/ comparacion[cifras] = '3';
        if (arr[0] == '1' && arr[1]=='0' && arr[2]=='0') /*100*/ comparacion[cifras] = '4';
        if (arr[0] == '1' && arr[1]=='0' && arr[2]=='1') /*101*/ comparacion[cifras] = '5';
        if (arr[0] == '1' && arr[1]=='1' && arr[2]=='0') /*110*/ comparacion[cifras] = '6';
        if (arr[0] == '1' && arr[1]=='1' && arr[2]=='1') /*111*/ comparacion[cifras] = '7';
        largo = largo -3; //restaOctal
    }
    
    for(i=0; i< distEntDat/3; i++){
        printf("%c",comparacion[i]);
    }
}