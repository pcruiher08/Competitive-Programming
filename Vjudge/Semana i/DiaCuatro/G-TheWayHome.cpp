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

int main(){
sync;
int n, d; 
cin>>n>>d; 
string campo; 
cin>>campo;
bool sePuedeLlegar = true;
int brincos = 0; 
FOR(i,0,d+1,1)campo.pb('0');

FOR(i,0,n,0){
    int j;
    int k = i;
    for(j = k+d; j>k; j--){//para atras
        if(campo[j]=='1'){
            i = j; 
            brincos++;
            if(i == n - 1){
                //salgo aqui

               // cout<<"Aqui mero"<<endl;
                cout<<brincos<<endl; 
                return 0; 
            }
            break;
        }
    
    }
//Acabo
    if(j - k == 0) {
        cout << -1 << endl;
        return 0;
    }

}

return 0;
}



