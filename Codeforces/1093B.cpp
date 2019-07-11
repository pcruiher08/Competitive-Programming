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

bool isAlwaysPal(string a){
    if(a.length()==1) return true;

    int arr[26];
    for(int i=0; i<26; i++){
        arr[i] = 0;
    }
    for(int i=0; i<a.length(); i++){
        arr[a[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        if(arr[i]%2==1){
            return false;
        }
    }
    return true;
}

string constructNonPal(string a){
    int arr[26];
    for(int i=0; i<26; i++){
        arr[i] = 0;
    }
    for(int i=0; i<a.length(); i++){
        arr[a[i]-'a']++;
    }

    char oddLetter;

    for(int i=0; i<26; i++){
        if(a.length()%2==1){
            if(arr[i]%2==1){
                oddLetter = i+'a';
                break;
            }
        }else{
            if(arr[i]>0){
                oddLetter = i+'a';
                break;
            }
        }
    }

    for(int i=0; i<a.length(); i++){
        if(a[i]==oddLetter){
            char aux; 
            aux = a[0];
            a[0] = oddLetter; 
            a[i] = aux;
            break;
        }
    }

    for(int i = 0; i<=a.length()/2; i++){
        if(i==a.length()/2) return "PABLO";
        if(a[i] == a[a.length()-1-i]){
            char aux; 
            aux = a[i];
            a[i] = a[i+1];
            a[i+1] = aux;
        }else{
            break;
        }
    }
    string res = "";
    for(int i=0; i<a.length(); i++){
        res+=a[i];
    }

    return res;
}


int main(){
sync;
int n; 
cin>>n;
while(n--){
    string s; 
    cin>>s;
    string res = constructNonPal(s);

    if(res=="PABLO"){
        cout<<-1<<endl;
    }else{
        cout<<res<<endl;
    }

}
return 0;
}

/*
3
aa
abacaba
xdd
*/