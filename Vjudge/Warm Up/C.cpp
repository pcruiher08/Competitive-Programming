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

int main(){
sync;
int n; cin>>n; 
//vector<int> books;
int books[2*100000+100];
int izq=0, der=0;
int c = 1; 
//books[0]=izq;
while(n--){

    char query; cin>>query;
    int book; cin>>book;
    if(c == 1){
        books[book] = izq--;
        c++;
        der++;
        goto here;
    }   
    if(query=='L') /*books.insert(books.begin(), book);*/books[book]=izq--;
    if(query=='R') /*books.pb(book);*/books[book]=der++;
    if(query=='?'){
        cout<<min(abs(books[book]-izq), abs(books[book]-der))-1<<endl;
/*
        vector<int>::iterator it = find(books.begin(), books.end(), book);
        cout<<min((int)distance(books.begin(), it), (int)(books.size()-distance(books.begin(), it)-1))<<endl;
*/

    }
    here: ;

}

return 0;
}