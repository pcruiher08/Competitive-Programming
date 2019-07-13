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

void cambio(string s, bool especial){
	
	if(!especial){
	    s[0]=toupper(s[0]);
		FOR(i,1,s.length(),1){
	        s[i] = tolower(s[i]);
	    }
	}else{
		FOR(i,0,s.length(),1){
	        s[i] = tolower(s[i]);
	    }
	}	
    cout<<s<<endl;
}

int main(){
sync;
string a; cin>>a; 
bool isFirstLower = false; 
bool areAllUpper = true;

if(a[0]<='z'&&a[0]>='a'){
	isFirstLower = true;
}
	
FOR(i,1,a.length(),1){
	if(a[i]<='z'&&a[i]>='a'){
		areAllUpper = false;
		break;
	}
}

if(areAllUpper && !isFirstLower){
	//se cambia
	cambio(a, true);
	return 0;
}

if(areAllUpper && isFirstLower){
	//se cambia
	cambio(a, false);
	return 0;
}

cout<<a<<endl;
return 0;
}
