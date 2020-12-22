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

string enlarge(string s){
    return s+s;
}

int main(){
sync;
int n; cin>>n;
string arr2[n];
string arr[n];
FOR(i,0,n,1){
    cin>>arr[i];
    arr2[i] = enlarge(arr[i]);
}

int veces[n];
FOR(i,0,n,1)veces[i]=0;

long long cuenta = 0;
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(i!=j){
            if(arr[j].size() == arr[i].size())
            if(arr2[j].find(arr[i]) != std::string::npos && veces[j] == 0 && veces[i]==0){

                //cout<<arr[i] << " "<<arr2[j]<<" "<<veces[i]<<" "<<veces[j]<<endl;
                veces[j]++;
                veces[i]++;
                i++;
                cuenta++;
            }
        }

    }
}
cout<<cuenta<<endl;
/*
7
word icpc rdwo dwor ordw pcic ccpi

*/

return 0;
}