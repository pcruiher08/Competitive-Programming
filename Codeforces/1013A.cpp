#include <iostream>
#include <vector>
using namespace std;
#define FORI(s,n) for(int i = s; i < n; i++)

int main() {
  int n;
  cin>>n;
  vector<int> x(n);
  int xs = 0;
  FORI(0,n) cin>>x[i], xs+=x[i];
  vector<int> y(n);
  int ys = 0;
  FORI(0,n) cin>>y[i], ys += y[i];
  cout<<(xs>=ys?"Yes":"No")<<endl;
  return 0;
}