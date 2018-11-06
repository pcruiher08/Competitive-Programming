#include <iostream>
using namespace std;
int main(){
    
    int p;
    scanf("%d",&p);
    int x, y;
    while(p--){
        int x1=0,y1=0,x2=0,y2=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x=x2-x1;
        y=y2-y1;
        if(x<1) x*=-1;
        if(y<1) y*=-1;
       printf("%d\n", x+y);
    }
}