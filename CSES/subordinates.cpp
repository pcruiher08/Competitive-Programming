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



struct employee{
    bool visited = false;
    vector<int> employees = {};
    int employeeamount = 0; 
};

employee tree[2 * 100001];


int dfs(employee &emp){

    if(!emp.visited){
        emp.visited = 1;
        for(auto hijo : emp.employees){
            emp.employeeamount += 1 + dfs(tree[hijo]);
        }
    }
    return emp.employeeamount;
    
}

int main(){
sync;

int n; cin>>n; 

for(int i = 2; i <= n; i++){
    int lec; cin >> lec; 
    tree[lec].employees.push_back(i);
}
for(int i = 1; i <= n; i++){
    cout<<dfs(tree[i]);
    if(i < n){
        cout<<" ";
    }else{
        cout<<endl;
    }

}



return 0;
}