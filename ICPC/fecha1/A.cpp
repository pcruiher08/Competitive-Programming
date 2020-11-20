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

struct elementos{
    vector<int> v; 
    int maxElem; 
    //bool variosMaximos;
};

int maxRepeating(int* arr, int n, int k){ 
    for (int i = 0; i< n; i++) 
        arr[arr[i]%k] += k; 
  
    int max = arr[0], result = 0; 
    for (int i = 1; i < n; i++){ 
        if (arr[i] > max){ 
            max = arr[i]; 
            result = i; 
        } 
    } 
    return result; 
} 

int main(){
sync;

int n, q; cin>>n>>q; 

vector<elementos > lista(n);

while(q--){
    char query;cin>>query;
    if(query == 'R'){
        int i,j; cin>>i>>j;
        
        lista[i].v.pb(j);

        if(lista[i].v.size() == 0){
            lista[i].maxElem = j;
        }else{
            if(lista[i].maxElem == j){
                lista[i].variosMaximos = true;
            }
            if(lista[i].maxElem < j){
                lista[i].maxElem = j; 
                lista[i].variosMaximos = false;
            }
        }
    }else if(query == 'Q'){
        int i; cin>>i;
        if(lista[i].v.size()){
            if(lista[i].variosMaximos){
                cout<<"Multiple"<<endl;
            }else{
                cout<<lista[i].maxElem<<endl;
            }
        }else{
            cout<<"No info"<<endl;
        }    
    }else{
        //B
        cout<<"un par"<<endl;
    }

} 

return 0;
}