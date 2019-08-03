#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

#define len 5
/*
decremento j
incremento i
incremento j
dectremento i


[0,0][0,1][0,2][0,3][0,4]
[1,0][][][][1,4]
[2,0][][][][2,4]
[3,0][][][][3,4]
[4,0][4,1][4,2][4,3][4,4]

SIN TERMINAR
*/


void spiralMat(int mat[][len]){
    int first = len;
    int cuentaPrimero = 0, cuentaSegundo = 0, cuentaTercero = 0, cuentaCuarto = 0;
    int i = len-1;
    int j = 0;
    while(len>1){
        for(; i>cuentaPrimero; i--){
            if(i==cuentaPrimero){
                cuentaPrimero++;
                break;
            }
        }

    }
}


int main(){
sync;



return 0;
}