#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
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
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

ll n , m , i;

ll calcula(ll find){
	ll left , right;
	if(i-find >= 0){
		left = find*(find+1)/2 + (i-find);
	}
	else{
		left = find*(find+1)/2 - (find-i)*(find-i+1)/2;
	}
	if(find <= n-i+1){
		right = find*(find+1)/2 + (n-i-find+1);
	}
	else{
		right = find*(find+1)/2 - (find+i-n-1)*(find+i-n)/2;
	}
	return (left + right - find);
}


ll binarySearch(){
	ll low = 1 , high = m;
	ll mid;
	ll result = -1;
	while(low<=high){
		mid = (low+high)/2;
		if(calcula(mid)>m){
			high=mid-1;
		}else{
			result = mid;
			low = mid+1;
		}
	}
	return result;
}

int main(){
sync;
    cin>>n>>m>>i;
	cout<<binarySearch();
}