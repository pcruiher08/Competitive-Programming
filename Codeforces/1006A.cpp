#include <iostream>
#include <vector>
using namespace std;
#define FORI(s,n) for(int i = s; i < n; i++)

int main() {
  int m;
  cin >> m;
  vector<int> a(m);
  FORI(0,m) cin >> a[i];
  FORI(0,m) cout<<(a[i]%2==0?a[i]-1:a[i])<<" ";
}
