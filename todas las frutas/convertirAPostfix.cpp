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

int prioridadAdentro(char str){ 
    if(str == '+' || str == '-') return 2;
    if(str == '*' || str == '/') return 4;
    if(str == '(') return -INF; 
} 
  
int prioridadAfuera(char str){
    if(str == '+' || str == '-') return 1;
    if(str == '*' || str == '/') return 3;
    if(str == '(') return INF; 
} 
  
void convierte(string str){ 
    stack<char> s; 
    FOR(i,0,str.length(),1){ 
        if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'){
            cout<<str[i];                       
        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(') { 
            if(s.empty()||(prioridadAfuera(str[i])>prioridadAdentro(s.top()))){
                s.push(str[i]); 
            }else{
                while(!s.empty()&&(prioridadAfuera(str[i])<prioridadAdentro(s.top())))cout<<s.top(), s.pop(); 
                s.push(str[i]); 
            } 
        }else if(str[i]==')'){ 
            while(s.top()!='(')cout<<s.top(),s.pop(); 
            s.pop();            
        } 
    } 
    //vacia
    while(!s.empty())cout<<s.top(),s.pop(); 
    
}  


int main(){
sync;
string revisa;
cin>>revisa;
//revisa = "A+B*(C+D*(E+F*(J+K*(H+I)+L)+M)+N)+P*Q";
convierte(revisa);
return 0;
}

/*
EJERCICIOS DE LA CLASE
//AB+CDE*FG+H+*I*J+*K*+L+
//ab+d+ef*+j+
//ABCD*+E+*FG*H*+I+
//ABCDEFJKHI+*+L+*+M+*+N+*+PQ*+
*/