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
#include <fstream>
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

struct name{
    string title; 
    int alphaValue; 
    int posValue;
    int total;
};

bool sortByAlpha(name a, name b){
    return a.title < b.title;
};

bool sortByTotal(name a, name b){

}

int main(){
sync;
ifstream file("p022_names.txt");
vector<name> v;
string read; 
while(file.good()){
    getline(file,read,',');
    string realName = string(read,1,read.length()-2);
    name toProcess; 
    toProcess.title = realName;
    int sum = 0;
    FOR(i,0,realName.length(),1)sum+=(realName[i]-'A'+1);
    toProcess.alphaValue = sum;
    v.pb(toProcess);
}
sort(v.begin(),v.end(),sortByAlpha);
ull totalSum = 0;
FOR(i,0,v.size(),1){
    v[i].posValue = i+1;
    if(i<100)
    cout<<v[i].posValue<<endl;
    v[i].total = v[i].posValue * v[i].alphaValue;
    totalSum += v[i].total;
}

cout<<totalSum;

return 0;
}