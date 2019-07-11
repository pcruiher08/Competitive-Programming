#include <iostream>
#include <vector>
using namespace std;


int main() {
  int n;
  int bound;
  int start; 
  int end;
  cin>>n>>bound;

  bool points[bound+1] = {false};

  while(n--){
    cin>>start;
    cin>>end;
    for(int i=start; i<=end; i++){
      points[i]=1;
    }
  }
  int cuenta = 0; 
  vector<int> indexes;
  for(int i=1; i<=bound; i++){
    if(!points[i]){
      cuenta++;
      indexes.push_back(i);
    }
  }
  cout<<cuenta<<endl;

  for(int i=0; i<indexes.size(); i++){
    if(i<indexes.size()-1)
    cout<<indexes[i]<<" ";
    else
    cout<<indexes[i];
  }
}