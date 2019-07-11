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
//sin terminar


ll fastPow(ll a,ll b){
    ll ret = 1;
    while(b>0){
        if(b&1) ret = (ret*a);
        a=(a*a);
        b>>=1;
    }
    return ret;
}

int main(){
sync;
//cin.ignore();
int n; 
cin>>n;
vector <int> arr[n]; 
string lec;
int guardaN = n; 
while(n--){
    //cout<<"n= "<<n<<endl;
    //getline(cin,lec);
    cin>>lec;
    vector<string> vec; 
    int index = 0; 
    index = lec.find('^');
    //cout<<index<<endl;
    string num;
    while(lec!=""){
        //cout<<index<<endl;
        if(index!=-1){
            num = lec.substr(0,index);
            //cout<<num<<endl;
            lec.erase(0,index+1);
            arr[n].pb(stoi(num));
        }else{
            arr[n].pb(stoi(lec));
            lec = "";
        }
    }
}


/*
3
2^2^2
3^4
9^2
*/


vector <ll> resp; 
FOR(i,0,guardaN,1){
    ll res = 1;
    FOR(j,0,arr[i].size()-1, 1){
        
        if(res!=1)
        res=fastPow(res,arr[i][j+1]);
        else
        res = fastPow(arr[i][j],arr[i][j+1]);
        resp.pb(res);
        cout<<res<<" ";
    }
    cout<<endl;
}

sort(resp.begin(), resp.end());
cout<<"....."<<endl;
FOR(i,0,guardaN,1)cout<<resp[i]<<endl;


return 0;
}