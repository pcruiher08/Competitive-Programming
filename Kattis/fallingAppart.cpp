#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int a = 0;
    int b = 0;
    cin >> n;
    vector<int> list(n);

  for (auto i = list.begin(); i != list.end(); i++) {
    cin>>*i;
  }

    sort(list.rbegin(), list.rend());


    for(int i = 0; i < list.size(); i++) {
        if(i % 2 == 0) {
            a+=list[i];
        }else{
            b+=list[i];
        }
    }

    cout << a << " " << b << endl;
}