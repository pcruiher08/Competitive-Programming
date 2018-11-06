#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin >>a>>b>>c;
    if((a==b&&b==c)&&(a+b+c==180)){
        cout<<"Equilateral";
        return 0;
    }
    if((a==b||a==c||b==c)&&(a+b+c==180)){
        cout<<"Isosceles";
        return 0;
    }
    if(a+b+c==180&&a!=0&&b!=0&&c!=0){
        cout<<"Scalene";
    }else{
        cout<<"Error";
    }
    return 0;
}