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


class UnionFind{

private:
  vi p, rank, setSize;
  int numSets;
public:
    UnionFind(int N){
        setSize.assign(N, 1); 
        numSets = N; 
        rank.assign(N, 0);
        p.assign(N, 0); 
        FOR(i,0,N,1) p[i] = i; 
    }
    int findSet(int i){return (p[i] == i) ? i : (p[i] = findSet(p[i]));} 

    bool isSameSet(int i, int j){return findSet(i) == findSet(j);}

    void unionSet(int i, int j){ 
        if(!isSameSet(i, j)){ 
            numSets--; 
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){p[y] = x; setSize[x] += setSize[y];}
            else{ 
                p[x] = y; setSize[y] += setSize[x];
                if(rank[x] == rank[y]) rank[y]++; 
            } 
        } 
    }

  int numDisjointSets(){ return numSets;}
  int sizeOfSet(int i){ return setSize[findSet(i)];}
};

int main(){
sync;
UnionFind uf(5);
uf.unionSet(0,1);
uf.unionSet(2,3);
uf.unionSet(4,3);
return 0;
}