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
#define FOR(m,s,n,u) for(ll m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define MRIT map<int,int>::reverse_iterator
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


int busca(map<int, int> m, int k){
    auto begin = m.begin();
    if(begin->first>k) return -1;

    auto end = m.end();
    end--;
    if(end->first < k) return end->first;

    auto find = m.find(k);

    if(find != m.end()) return k;

    auto lower = m.lower_bound(k);

    lower--;
    return lower->first;
}


void fastscan(int &x){
   char ch; bool f= 0; int a=0;
   while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));
   if(ch!='-')a*=10,a+=ch-'0';else f=1;
   while(((ch=getchar())>='0')&&(ch<='9'))a*=10, a+=ch-'0';
   if(f)a=-a;x=a;
}

int main(){
sync;
int n,p,q,s;
fastscan(n);
fastscan(p);
fastscan(q);
fastscan(s);
map<int,int> m;
map<int,int> hash; 
int arr[p]; FOR(i,0,p,1){int lec; fastscan(lec); arr[i] = lec;}
int arr2[q]; FOR(i,0,q,1){int lec; fastscan(lec); arr2[i] = lec; m[lec]++;}
sort(arr,arr+p);
//reverse(arr,arr+p);
//FOR(i,0,q,1)m[arr2[i]] = m[arr2[i]] + 1;

int izquierda = 0;
int derecha = mod;

while(izquierda<=derecha){
    hash = m;
    int diffs = 0;
    int centro = (izquierda+derecha)/2;
    ROF(i,0,p-1,1){
        int y = min(s-arr[i],arr[i]+centro);
        if(y<arr[i]-centro){
            continue;
        }
        MRIT itera(hash.upper_bound(y));
        if(itera->first<arr[i]-centro || itera==hash.rend()){
            continue;
        }
        if(itera->second==1){
            hash.erase(itera->first);
        }else{
            itera->second--;
        }
        diffs++;
        if(diffs>=n){
            break;
        }
    }
    if(diffs>=n){
        derecha=centro-1;
    }else{
        izquierda=centro+1;
    }
}

/*
while(izquierda+1<derecha){
    map<int,int> hash(m);
    int difs = 0;
    int centro = (izquierda + derecha)/2;

    FOR(i,0,p,1){
        if(difs>=n){
            break;
        }
        int y = busca(hash, min(s-arr[i],arr[i]+centro));
        if(y>=arr[i]-centro && y!=-1){
            difs++;
            if(hash[y] - 1 == 0){
                hash.erase(y);
            }else{
                hash.emplace(y,hash[y] - 1);
            }
        }
    }

    if(difs>=n){
        derecha = centro;
    }else{
        izquierda = centro;
    }
}
*/
cout<<(izquierda>=mod?-1:izquierda)<<endl;


return 0;
}