#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    double res = ( n * 0.35) * 0.1;
    printf("%.0f\n", floor(res));
    return 0;
}

