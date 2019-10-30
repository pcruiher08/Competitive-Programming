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


int diferenciaAbsoluta(int *arr, int largo, int elem) {
    int ans=1;
    int i=0;
    while(i<largo&&ans){
        if(arr[i]==elem)ans=0;
        i++;
    }
    return ans;
}

set<int> s;

int main(){
sync;   int len,team,cuantos=0;
    cin>>len>>team;
    int escuela[len],arr[team];
    FOR(i,0,len,1)cin>>escuela[i];
    int j=0;
    while(cuantos<team && j<len) {
        if(diferenciaAbsoluta(escuela,j,escuela[j])) {
            arr[cuantos]=j+1;
            cuantos++;
        }
        j++;
    }
    if(cuantos==team) {
        cout<<"YES"<<endl;
        FOR(i,0,team,1) cout<<arr[i]<<" ";
    }else{
        cout<<"NO"<<endl;
    }
    return 0;


}
