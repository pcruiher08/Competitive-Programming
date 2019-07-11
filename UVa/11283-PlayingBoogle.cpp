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
#define PI 3.1415926535897932384626433832795028841971
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

int main(){
sync;

int letters[26];

int n; cin>>n;

FOR(o,0,n,1){
    memset(letters,0,sizeof(letters));
    char aux;
    FOR(i,0,16,1){cin>>aux; letters[aux-'A']++;}

    FOR(i,0,26,1)cout<<letters[i]<<" ";
    cout<<endl;
    FOR(i,0,26,1)cout<<(char)(i+'A')<<" ";
    cout<<endl;

    int queries; cin>>queries; 
    int points = 0;
    while(queries--){
        //points = 0;
        string query; cin>>query;
        int queryLetters[26]; memset(queryLetters,0,sizeof(queryLetters));
        FOR(i,0,query.length(),1) queryLetters[query[i]-'A']++;
        FOR(i,0,26,1)cout<<queryLetters[i]<<" ";
        cout<<endl;
        FOR(i,0,26,1)cout<<(char)(i+'A')<<" ";
        cout<<endl;
        int len = query.length();
        bool flag = true;
        FOR(i,0,26,1){
            if(queryLetters[i]){
                if(letters[i]-queryLetters[i]<0){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            /*
            3 - > 1 
            4 - > 1 
            5 - > 2
            6 - > 3
            7 - > 5
            8 - > 11
            */
            cout<<"found : "<<query<<endl;
            int toSum = 0;
            if(len==4||len == 3)toSum=1;
            if(len==5)toSum=2;
            if(len==6)toSum=3; 
            if(len==7)toSum=5;
            if(len>=8)toSum=11;
            points += toSum;
            cout<<"+ "<< toSum<<endl;
        }
    }


   /*

2
TNXO
AAEI
IOSR
BFRH
8
TAXES
RISE
ANNEX
BOAT
OATS
FROSH
HAT
TRASH
FNEI
OBCN
EERI
VSIR
1
BEER
    */
   cout<<"Score for Boogle game #"<<o+1<<": "<<points<<endl;
}
return 0;
}