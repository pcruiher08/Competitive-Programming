#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=2; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define pb push_back
#define mod 1000000009
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>

struct punto{
    int x;
    int y;
};

ll areaTriangulo(punto a, punto b, punto c) {
    return a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x;
}

using namespace std;
int main(){
    sync;
    int n;
    cin>>n;
    punto puntos[n];
    ll cuantosTriangulos = 0;
    for(int i=0; i<n; i++){
        cin>>puntos[i].x>>puntos[i].y;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(areaTriangulo(puntos[i],puntos[j],puntos[k])!=0){
                    cuantosTriangulos++;
                }
            }
        }
    }
    cout<<cuantosTriangulos;
    
}