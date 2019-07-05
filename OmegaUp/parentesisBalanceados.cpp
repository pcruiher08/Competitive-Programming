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

bool Brackets(char opening, char closing){
	if( opening == '(' && closing == ')' ) return true;
	else if ( opening == '[' && closing == ']' ) return true;
	else if ( opening == '{' && closing == '}' ) return true;
	return false;
}

bool BalancedParentheses(string b){
	stack<char> a;
	for(int i = 0; i < b.length(); i++){
		if( b[i] == '(' || b[i] == '{' || b[i] == '[' )
			a.push(b[i]);
		else if( b[i] == ')' || b[i] == '}' || b[i] == ']' ){
			if( a.empty() || !Brackets( a.top(), b[i] ) )
				return false;
			else
				a.pop();
		}
	}
	return a.empty();
}
int main(){
	sync;	

    int a = 1; 
    //cin>>a;
    while(a--){
	    string c;
        cin >> c;
        if(BalancedParentheses(c))
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
    }
}