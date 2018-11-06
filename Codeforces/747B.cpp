#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=2; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000009
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>

using namespace std;
int main() {
    sync;
    int n = 0;
    string s;
    cin>>n>>s;
    int countInter = 0;
    int maximo = -1;
    int toMax = 0;
    int countA = 0, countC = 0, countG = 0, countT = 0;
    for(int i=0; i<n;i++){
        if(s[i]=='?')countInter++;
        if(s[i]=='A') countA++;
        if(s[i]=='G') countG++;
        if(s[i]=='T') countT++;
        if(s[i]=='C') countC++;
    }
    
    if(countA>0) maximo=countA;
    if(countC>maximo) maximo=countC;
    if(countG>maximo) maximo=countG;
    if(countT>maximo) maximo=countT;
     
    //maximo = max(countA,max(countC,max(countG,countT)));
    int realmaximo = n/4;
    toMax += maximo-countA;
    toMax += maximo-countC;
    toMax += maximo-countG;
    toMax += maximo-countT;

    if(n%4!=0/*||n%maximo*4!=0*/||maximo*4>n||realmaximo<maximo){
        cout<<"===";
        return 0;
    }
    vector <char> dna;
    char adn[n];
    int indexes[n];
    int cuentaIndexes = 0;
    for(int i=0; i<n; i++){
        if(s[i]!='?') adn[i]=s[i];
        if(s[i]=='?'){
            indexes[cuentaIndexes]=i;
            cuentaIndexes++;
        }
    }
    int cuentaFaltantes = 0;

    while(countA<realmaximo){
        dna.pb('A');
        countA++;
    }
    while(countC<realmaximo){
        dna.pb('C');
        countC++;
    }
    while(countG<realmaximo){
        dna.pb('G');
        countG++;
    }
    while(countT<realmaximo){
        dna.pb('T');
        countT++;
    }
    for(int i=0; i<cuentaIndexes; i++){
        adn[indexes[cuentaFaltantes++]] = dna[i];
    }
    for(int i=0; i<n; i++){
        cout<<adn[i];
    }
}