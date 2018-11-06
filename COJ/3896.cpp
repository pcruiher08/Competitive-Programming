#include <iostream>

using namespace std; 

int main(){
  int x; 
  int y; 
  int x1,y1, x2,y2; 
  
  cin>>x>>y>>x1>>y1>>x2>>y2;
  int xini, yini; 
  int xfin, yfin;
  if(x1==x2){
    xini=0; 
    yini=(y1>y2)?y2:y1;
    xfin = x;
    yfin = (y1>y2)?y1:y2;
  }
  if(y1==y2){
    yini=0;
    xini= (x1>x2)? x2:x1;
    xfin = (x1>x2)? x1:x2;
    yfin = y;
  }
  
  if(x1!=x2){
    xini=(x1>x2)? x2:x1;
    yini=0;
    xfin=(x1>x2)? x1:x2;
    yfin=y;
  }
  
  
  cout<<xini<<" "<<yini<<" "<<xfin<<" "<<yfin;
  
  
}