#include <iostream>
/*
  printf ("Enter your family name: ");
  scanf ("%79s",str);  
  printf ("Enter your age: ");
  scanf ("%d",&i);
  printf ("Mr. %s , %d years old.\n",str,i);
  printf ("Enter a hexadecimal number: ");
  scanf ("%x",&i);
  printf ("You have entered %#x (%d).\n",i,i);
  
*/
int main(){
  int x=0;
  while(!x){
  int d, m, a, dD=11, mD=11, aD=11, c;
  //cin>>d>>m>>a;
  scanf("%d%d%d",&d,&m,&a);
  dD-=d;
  dD*=-1;
  mD-=m;
  mD*=-1;
  aD-=a;
  aD*=-1;
  if(dD<0||(dD==0&&mD<0)||(dD==0&&mD==0&&aD<0)){
    //cout<<-1;
    printf ("-1\n");
    break;
  }
  c+=dD*1440;
  c+=mD*60;
  c+=aD;
  //cout<<c;
  printf ("%d\n",c);
  x++;
  }
  
}

