#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
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
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;
int avanzoEnX,atrasoEnX, avanzoEnY, atrasoEnY;
int deboAvanzarX, deboAvanzarY, deboAtrasarX, deboAtrasarY;
int dondeEstoyX, dondeEstoyY;
int desiredX,desiredY;
int n;

bool sePuedeConstruir(int nuevoLargo, int estoyX, int estoyY, int quieroX, int quieroY){
    int deltaDitancia = abs(estoyX - quieroX) + abs(estoyY - quieroY);
    if(deltaDitancia%2 != nuevoLargo%2){
        return false;
    }else{
        if(nuevoLargo>=deltaDitancia){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

bool sePuedeCambiar(int nuevoLargo, string pasos){
    
    int leftPointer, rightPointer;
    leftPointer = 0;
    rightPointer = nuevoLargo;

    int nuevaPosX = 0, nuevaPosY = 0;
    //cout<<"A"<<endl;

    FOR(i,nuevoLargo,n,1){
        if(pasos[i]=='D'){
            nuevaPosY--;
        }else if(pasos[i]=='U'){
            nuevaPosY++;
        }else if(pasos[i]=='R'){
            nuevaPosX++;
        }else if(pasos[i]=='L'){
            nuevaPosX--;
        }
    }
    //cout<<"B"<<endl;

    while(1){
        /*
        cout<<"new len "<<nuevoLargo<<" n "<<n<<endl;
        cout<<"de perdido entre"<<endl;
        cout<<"rightPointer: "<<rightPointer<<" , leftPointer: "<<leftPointer<<endl;
        cout<<"newX: "<<nuevaPosX<<" ,nuevaaPosY: "<<nuevaPosY<<endl;
        */
        //cout<<"n = "<<n<<" r= "<<rightPointer<<endl;
        if(sePuedeConstruir(nuevoLargo,nuevaPosX,nuevaPosY,desiredX,desiredY)){
          //  cout<<"true ya me voy"<<endl;
            return true;
        }
        if(rightPointer == n) break;

        //cout<<pasos[leftPointer]<<" , "<<pasos[rightPointer]<<endl;
        
        if(pasos[leftPointer]=='D'){
            nuevaPosY--;
        }else if(pasos[leftPointer]=='U'){
            nuevaPosY++;
        }else if(pasos[leftPointer]=='R'){
            nuevaPosX++;
        }else if(pasos[leftPointer]=='L'){
            nuevaPosX--;
        }
        leftPointer++;

        if(pasos[rightPointer]=='D'){
            nuevaPosY++;
        }else if(pasos[rightPointer]=='U'){
            nuevaPosY--;
        }else if(pasos[rightPointer]=='R'){
            nuevaPosX--;
        }else if(pasos[rightPointer]=='L'){
            nuevaPosX++;
        }
        rightPointer++;

    }
   // cout<<"C"<<endl;
return false;



}

int main(){
sync;
cin>>n; 
vector<int> indexesOfR, indexesOfU, indexesOfL, indexesOfD;
int leftPointer = -1, rightPointer = n;
string pasos; cin>>pasos;
 cin>>desiredX>>desiredY;
if(!sePuedeConstruir(n,0,0,desiredX,desiredY)){
    cout<<-1<<endl;
    return 0;
}

    while(rightPointer-leftPointer>1){
       // cout<<"sigo en el ciclo"<<endl;
        int midPointer = (leftPointer+rightPointer)/2;
        if(sePuedeCambiar(midPointer,pasos)){
            rightPointer = midPointer;
         //   cout<<"right"<<endl;
        }else{
            leftPointer = midPointer;

           // cout<<"left"<<endl;
        }
    }


cout<<rightPointer<<endl;
return 0;
}