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
#define MAX 300
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

map <string, int> mapita;

int total, grafo[MAX][MAX];

int agrega(string str){
    if(mapita.count(str)) return mapita[str];
    total = mapita.size();
    mapita[str] = ++total;
    return mapita[str];
}


int main(){
    int n, m;
    int guardaN, guardaM;
    guardaN = n;
    guardaM = m;
    cin>>n>>m;
    while(n--){
        int x, y;
        string lec,basura;
        cin>>lec;
        x = agrega(lec);
        cin>>basura>>basura>>basura>>lec;
        y = agrega(lec);
        grafo[x][y] = 1;
    }
    FOR(i,1,total+1,1)FOR(j,1,total+1,1)FOR(k,1,total+1,1)grafo[j][k] |= grafo[j][i] && grafo[i][k];

    while(m--){
        int x, y;
        string lec, basura;
        cin>>lec;
        x = agrega(lec);
        cin>>basura>>basura>>basura>>lec;
        y = agrega(lec);

        if(grafo[x][y])cout<<"Fact"<<endl;
        else if(grafo[y][x])cout<<"Alternative Fact"<<endl;
        else cout<<"Pants on Fire"<<endl;
    }
    return 0;
}

