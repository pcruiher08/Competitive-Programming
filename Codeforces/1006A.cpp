#include <iostream>
#include <vector>
using namespace std;
#define FORI(s,n) for(int i = s; i < n; i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  FORI(0,n) cin >> a[i];
  FORI(0,n) cout<<(a[i]%2==0?a[i]-1:a[i])<<" ";
}
