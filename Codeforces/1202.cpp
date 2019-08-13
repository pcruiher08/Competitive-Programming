#include <bits/stdc++.h> 
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

string reverse(string a){
    string b = ""; 
    ROF(i,0,a.length()-1,1){
        b+=a[i];
    }
    return b;
}

string addBinary(string a, string b) { 
    string result = "";
    int s = 0;
    int i = a.size() - 1, j = b.size() - 1; 
    while (i >= 0 || j >= 0 || s == 1){ 
        s += ((i >= 0)? a[i] - '0': 0); 
        s += ((j >= 0)? b[j] - '0': 0); 
        result = char(s % 2 + '0') + result;
        s /= 2; 
        i--; j--; 
    } 
    return result; 
} 

int main(){
sync;
int n; cin>>n; cin.ignore();
while(n--){
    string a, b; 
    getline(cin,a);
    getline(cin,b);
    string sum = "";
    sum = addBinary(a,b);
    cout<<reverse(sum)<<endl;
}
return 0;
}