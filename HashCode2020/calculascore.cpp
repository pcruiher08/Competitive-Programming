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
#include <fstream>
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

int main(){
sync;

ifstream entrada1,entrada2,entrada3,entrada4,entrada5,entrada6,entrada1IN,entrada2IN,entrada3IN,entrada4IN,entrada5IN,entrada6IN;

entrada1.open("a_output.txt", std::ios_base::in);





entrada2.open("b_output.txt", std::ios_base::in);
entrada3.open("c_output.txt", std::ios_base::in);
entrada4.open("d_output.txt", std::ios_base::in);
entrada5.open("e_output.txt", std::ios_base::in);
entrada6.open("f_output.txt", std::ios_base::in);


vi booksValues1;

int howManyBooks1;
int howManyLibraries1; 
int daysForScanning1;
entrada1IN.open("a_example.txt", std::ios_base::in);
entrada1IN>>howManyBooks1;
entrada1IN>>howManyLibraries1;
entrada1IN>>daysForScanning1;


for(int i=0; i<howManyBooks1; i++){
    int x;
    entrada1IN>>x;
    booksValues1.pb(x);
}


vi booksValues2;

int howManyBooks2;
int howManyLibraries2; 
int daysForScanning2;
entrada2IN.open("b_read_on.txt", std::ios_base::in);
entrada2IN>>howManyBooks2;
entrada2IN>>howManyLibraries2;
entrada2IN>>daysForScanning2;


for(int i=0; i<howManyBooks2; i++){
    int x;
    entrada2IN>>x;
    booksValues2.pb(x);
}

int cuantas = 0; 
int basura, libros;

ull points = 0;

entrada1>>cuantas;
while(cuantas--){
    entrada1>>basura; 
    entrada1>>libros; 
    int x;
    while(libros--){
        entrada1>>x;
        points+=booksValues1[x];
    }
}
entrada1.close();


entrada2>>cuantas;


while(cuantas--){
    entrada2>>basura; 
    entrada2>>libros; 
    int x;
    while(libros--){
        entrada2>>x;
        points+=booksValues2[x];
    }
}

cout<<points;
entrada2.close();

return 0;
}