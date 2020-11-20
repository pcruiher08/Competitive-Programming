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
#include <sstream>
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

int const N = 1000000;
int isPrime[N];

bool sieve() {
    int i=2;
    while(i*i <= N) {
        if(isPrime[i] == 0) {
            i++;
            continue;
        }
        int j = 2*i;
        while(j < N) {
            isPrime[j] = 0;
            j += i;
        }
        i++;
    }
}

void permutations(string str, int n, string res, vector<string> &perms){
    if(n == 1){
        perms.pb(res+str);
        return;
    }
    FOR(i,0,n,1){
        permutations(str.substr(1), n - 1, res + str[0],perms);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

int recorre(vector<string> nums){
    for(int i=0; i<nums.size(); i++){
        int lenOfNum = nums[i].length();
        int num = 0;
        stringstream tonum(nums[i]);
        tonum >> num;
        if(to_string(num).size() == lenOfNum){
            if(isPrime[num]){
                return num;
            }
        }
    }
    return false; 
}

int main(){
sync;
for(int i=0; i<N; i++) {
    isPrime[i] = 1;
}

isPrime[0] = 0;
isPrime[1] = 0;
sieve();
string k; cin>>k; 
vector<int> posibles; 
string vacioK = "";

vector<string> permsOfK; 
permutations(k,k.length(),vacioK,permsOfK);
FOR(i,0,permsOfK.size(),1){
    FOR(j,1,permsOfK[i].length(),1){
        FOR(k,j+1,permsOfK[i].length(),1){
            string parte1 = permsOfK[i].substr(0,j);
            string parte2 = permsOfK[i].substr(j,k-j);
            string parte3 = permsOfK[i].substr(k,permsOfK[i].length()-k);
            //cout<<parte1<<" "<<parte2<<" "<<parte3<<endl;
            vector<string> p1,p2,p3;
            string vacio1 = "", vacio2 = "", vacio3 = "";
            permutations(parte1,parte1.length(),vacio1,p1);
            permutations(parte2,parte2.length(),vacio2,p2);
            permutations(parte3,parte3.length(),vacio3,p3);
            sort(p1.begin(),p1.end());
            sort(p2.begin(),p2.end());
            sort(p3.begin(),p3.end());

            int primero = recorre(p1);
            int segundo = recorre(p2);
            int tercero = recorre(p3);
            if(primero && segundo && tercero){
            //cout<<primero<<" "<<segundo<<" "<<tercero<<endl;

                posibles.pb(primero * segundo * tercero);
            }

        }
    }

}

sort(posibles.begin(), posibles.end());
if(posibles.size()){
    cout<<posibles[0]<<endl;
}else{
    cout<<"Bob lies"<<endl;
}

return 0;
}