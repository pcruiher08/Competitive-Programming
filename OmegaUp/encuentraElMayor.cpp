#include <iostream>
using namespace std;
int main()
{
    int m;
    cin>>m;
    int array[m-1];
    int cuenta = 0;
    while(cuenta<m){
        cin>>array[cuenta];
        cuenta++;
    }
    int temp = 0;
    for(int i=0;i<m;i++)
    {
        if(array[i]>temp)
        temp=array[i];
    }
    cout << temp << endl;
}