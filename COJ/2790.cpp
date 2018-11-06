#include <iostream>
#include <set>
#define W(t) while(t--)
using namespace std;
int main(){


	int r,p,w;
 set<int> s;
 cin >> r >> p;
  W(p)
  {cin >> w;
   s.insert(w);

}
  cout << r-s.size();
}