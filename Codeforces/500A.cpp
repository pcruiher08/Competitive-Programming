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

int main(){
sync;
int nums, desired; 
cin>>nums>>desired; 
nums-=1;
desired-=1;

int arr[nums];
for(int i=0; i<nums; i++)cin>>arr[i];

/*
FOR(i,0,nums,1)cout<<arr[i]<<" ";
cout<<endl;
FOR(i,0,nums,1)cout<<i<<" ";
cout<<endl;
*/


int i = 0;
while(true){

    if(i>nums)break;
    //cout<<"visitado "<<i+1<<endl;
    if(i==desired){
        cout<<"YES"<<endl;
        return 0;
    }
    i = arr[i] + i;
    //cout<<"aqui ando "<<i<<endl;

}


cout<<"NO"<<endl;

return 0;
}