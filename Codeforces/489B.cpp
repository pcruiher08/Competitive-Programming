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
 
int howManyPairs(int menor[], int mayor[], int menorCuantos, int mayorCuantos){
    //int countArriba = 0; 
    //int countAbajo = 0;
    int bound = 0;
 
    int parejitasAgarraditasDeLaMano = 0;
    FOR(countAbajo,0,mayorCuantos,1){
        FOR(countArriba,bound,menorCuantos,1){
            int resta = abs(menor[countArriba] - mayor[countAbajo]);
            if(resta <= 1){
                //cout<<"parejitas: "<<menor[countArriba]<<" y "<<mayor[countAbajo]<<endl;
                parejitasAgarraditasDeLaMano++;
                bound = countArriba + 1;
                break;
            }
        }
    }
    return parejitasAgarraditasDeLaMano;
}
 
/*
4
1 4 6 2
5
5 1 5 7 9
 
*/
 
int main(){
    sync;
    int boys; int girls;
    cin>>boys;
    int arrBoys[boys];
 
 
 
    FOR(i,0,boys,1)cin>>arrBoys[i];
    cin>>girls;
    int arrGirls[girls];
    FOR(i,0,girls,1)cin>>arrGirls[i];
    sort(arrBoys, arrBoys+boys);
    sort(arrGirls, arrGirls+girls);
    if(boys==girls) cout<<howManyPairs(arrBoys,arrGirls,boys,girls)<<endl;
    else
    cout<<howManyPairs(boys<girls?arrBoys:arrGirls,boys>girls?arrBoys:arrGirls,min(boys,girls), max(boys,girls));
    return 0;
}