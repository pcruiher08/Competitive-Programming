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

void printArr(int from, int to, int arr[]){
    cout<<"from "<<from<<" to "<<to<<endl;
    FOR(i,from,to,1){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
sync;


int n; cin>>n;
int arr[n];
int fen[n];
int suma = 0;
FOR(i,0,n,1){
    cin>>arr[i];
    fen[i] = arr[i];
    if(i > 0){
        fen[i] = fen[i] + fen[i - 1];
    }
    suma += arr[i];
}


//cout<<"suma / 3 = "<< suma / 3 <<endl;

int cuenta = 0;

FOR(i,0,n,1){
    //cout<<fen[i] <<endl;
    if(fen[i]  == suma / 3 ){
        //encontre una particion
        //cout<<"particion "<<i<<endl;
        //printArr(0,i + 1,arr);


        FOR(j,i + 1,n,1){
            //cout<<fen[j] << " /// "<<arr[j]<<endl;
            if(fen[j] - fen[i] == suma / 3 && j + 1 != n){
                cuenta++;
                //printArr(i + 1,j + 1,arr);
                //printArr(j + 1,n,arr);
            }
        }
    }
}
cout<<cuenta<<endl;




return 0;
}