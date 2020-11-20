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

ll n;
char mat[10][10];

ll recursion(ll nivel,ll barcos[]){
    ll cuenta = 0;
    if(nivel==0){
        cuenta = 1;
        FOR(i,0,n,1){
            FOR(j,0,n,1){
                if(mat[i][j]=='O')
                    cuenta=0;
            }
        }
    }else{
        nivel--;
        char guarda[barcos[nivel]];
        int tam = barcos[nivel];
        FOR(i,0,n,1){
            FOR(j,0,n-tam+1,1){
                bool flag = true;
                FOR(k,0,tam,1){
                    if(mat[i][j+k]=='#'||mat[i][j+k]=='X'){
                        flag=false;
                    }
                }
                if(flag){
                    FOR(k,0,tam,1){
                        guarda[k]=mat[i][j+k];
                        mat[i][j+k]='#';
                    }
                    cuenta+=recursion(nivel,barcos);
                    FOR(k,0,tam,1){
                        mat[i][j+k]=guarda[k];
                    }
                }
            }
        }

        if(tam-1 != 0){
                FOR(i,0,n,1){
                    FOR(j,0,n-tam+1,1){
                    bool flag=true;
                    FOR(k,0,tam,1){
                        if(mat[j+k][i]=='#'||mat[j+k][i]=='X'){
                            flag=false;
                        }
                    }
                    if(flag){
                        FOR(k,0,tam,1){
                            guarda[k]=mat[j+k][i];
                            mat[j+k][i]='#';
                        }
                        cuenta+=recursion(nivel,barcos);
                        FOR(k,0,tam,1){
                            mat[j+k][i]=guarda[k];
                        }
                    }
                }
            }
        }
    }

    return cuenta;
}


int main(){
sync;
ll k; cin>>n>>k;
ll barcos[k];

FOR(i,0,n,1)FOR(j,0,n,1)cin>>mat[i][j];
FOR(i,0,k,1)cin>>barcos[i];
sort(barcos, barcos+k);
ll res = recursion(k, barcos);
cout<<res<<endl;


return 0;
}