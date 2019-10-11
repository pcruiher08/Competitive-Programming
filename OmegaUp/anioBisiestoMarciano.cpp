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
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;



int main(){
    sync;
    long long int dia, mes, anio, diasAnio, total= 0;
    cin>>dia>>mes>>anio;
    if(anio==2001){
        total+=((mes-1)*57)%7;
        if(mes>2)total+=2;
        total+=dia;
    }else{
        diasAnio=(anio-2000)/5;
        if(anio%5==0)diasAnio--;
        total+=((anio-diasAnio-2000)*686+diasAnio*685)%7;
        total+=((mes-1)*57)%7;
        if(mes>2){
            total+= 2;if(anio%5==0)total--;
        }
        total+=dia;
    }
    cout<<(total%7?total%7:7)<<endl;
}