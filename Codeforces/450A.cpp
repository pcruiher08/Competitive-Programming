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
#include <deque> 
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

struct child{

    int candies;
    int position;

};

int main(){
sync;

int n; cin>>n;
int m; cin>>m;
deque<child> q;
FOR(i,0,n,1){
    int lec; cin>>lec;
    child aux;
    aux.candies = lec;
    aux.position = i+1;
    q.push_front(aux);
}

int ganador = 1;

while(!q.empty()){
    child checa;
    checa = q.back();
    checa.candies -= m;
    ganador = checa.position;
    q.pop_back();
    if(checa.candies > 0){
        q.push_front(checa);
    }
}


cout<<ganador<<endl;





return 0;
}