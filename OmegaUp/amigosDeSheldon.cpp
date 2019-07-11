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
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;

struct amigo{
  string nombre; 
  int edad; 
  string actividad;
};

bool func(amigo a, amigo b){
  if(a.edad>b.edad)
  return true; 
  return false;
}

void printAmigo(amigo a){
  cout<<a.nombre<<" "<<a.edad<<" "<<a.actividad<<endl;
}

int main() {
  sync;
  int n;
  cin>>n;
  string nombre,actividad; 
  int edad;
  amigo amigos[n];
  FOR(i,0,n,1) cin>>nombre>>edad>>actividad, cin.ignore(1,'\n'), amigos[i].nombre=nombre, amigos[i].edad=edad, amigos[i].actividad=actividad;
  sort(amigos, amigos+n, func);
  FOR(i,0,n,1) printAmigo(amigos[i]);
}