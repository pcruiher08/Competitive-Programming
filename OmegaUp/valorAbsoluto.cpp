#include <iostream>

using namespace std;

int main()
{
    int x; 
    int n;
    int b = -1;
   cin >> n;
   cin >> x;
   int q = n+x; 
   if(q<0){
       q=q*b;
   }
   cout << q;
   
   return 0;
}
