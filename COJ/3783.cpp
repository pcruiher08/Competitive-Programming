
#include <iostream>
#include <math.h>




int main(){
    unsigned int nu;
    scanf("%i", &nu);
    while(nu--){
        unsigned int n,k,sum=0;
        scanf("%i%i",&n,&k);
        
        for(int i=1; i<=sqrt(n); i++){
            if(n%i==0&&i%k!=0&&(n/i)!=i){
                sum+=i;
            }
            if(n%i==0&&i!=1&&(n/i)%k!=0){
                sum+=n/i;
            }
            if(i==1&&(n%k)!=0){
                sum+=n;
                
            }
            
        }
            printf("%i\n", sum);
        }
    }
    /*
     20
     1 2 4 5 8 10 20
     
     2
     2 4 8 10 20
     
     -> 1 5 = 6
     
     5
     20 2
     10 1
     20 5
     7 5
     20 40 -> 1 2 4
     
     
     
     
     6
     0
     7
     8
     42
     */