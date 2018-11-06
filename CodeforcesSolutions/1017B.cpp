

#include <iostream>
using namespace std;

int main() {
  int n;
  string str, str2;
  cin>>n>>str>>str2;
  long long falses = 0, trues = 0, ne = 0, ans = 0;
  for (int i = 0; i < n; i++){
    if (str[i] == '1')
      trues++;
    else
      falses++;
    if (str[i] == '1' and str2[i] == '0')
      ne++;
  }
  for (int i = 0; i < n; i++)
    if (str[i] == '1' and str2[i] == '0')
      ans += falses;
    else if (str[i] == '0' and str2[i] == '0')
      ans += trues - ne;
  cout << ans << endl;
  return 0;
}