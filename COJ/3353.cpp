
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


int main(){
    int n,e,suma=0,g;
    cin>>n>>e;
    vector<int> a(n);
    for (int x=0; x<n; x++)
        cin >> a[x];
    sort(a.begin(), a.end());
    g=e;
    for (int x=0; x<e; x++){
        if (a[x] >= 0 || g == 0)
            break;
        else{
            suma += a[x];
            g--;
        }
    }
    printf("%u", abs(suma));
    return 0;
}

