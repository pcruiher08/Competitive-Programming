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

struct dato{
    int cuantosPasos; 
    int cuantosLlegan; 
    dato(){
        cuantosPasos = 0;
        cuantosLlegan = 0;
    }
};


int main(){
sync;
map<int,dato> m;

int key; 
int n; 
cin>>n>>key;
int maximiliano = -1;
int arr[n];
FOR(i,0,n,1)cin>>arr[i];
sort(arr,arr+n);
int menoresPasos = -1;
FOR(i,0,n,1){
    int aux; 

    aux = arr[i];
    if(aux>maximiliano)maximiliano = aux;
    int memoria = aux, pasos = 0;
    //m[aux].cuantosPasos = 0; 

    bool flag = true;
    while(aux>=0){
        if (m[aux].cuantosLlegan < key) {
            m[aux].cuantosPasos+=(pasos++);
            m[aux].cuantosLlegan++;
        }
        aux = floor(aux/2);
        if(!flag)break;
        if(!aux)flag = false;
        
    }
}

for (int i = 0; i < maximiliano + 1; i++) {
if(m[i].cuantosLlegan>=key){
        if(menoresPasos == -1 || m[i].cuantosPasos < menoresPasos){
            menoresPasos = m[i].cuantosPasos;
        }
        //return 0;
    }
}
cout<<menoresPasos<<endl;
return 0;
}