#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
/*

void printArr(string s, int len){
  for(int i=0; i<len; i++){
    cout<<s[i]<<" ";
  }
}
*/

//vector <int> cuentaSwaps(char s[], char t[]){}

int main() {
  int n;
  string s1;
  string t1;
  int busca;
  vector <int> pos; 
  bool igual;
  cin>>n;
  cin>>s1>>t1;


  if(s1==t1){
    cout<<0<<endl;
    return 0;
  }

  char s[s1.size()+1];
  s1.copy(s,s1.size()+1);
  s[s1.size()] = '\n';
  char t[t1.size()+1];
  t1.copy(t, t1.size()+1);
  t[t1.size()] = '\n';

  for(int i=0; i<n; i++){
    if(s[i]!=t[i]){
      igual = false;
      for(int j=i+1; j<n; j++){
        if(s[j]==t[i]){
          busca = j;
          igual = true;
          break;
        }
      }
      if(!igual){
        cout<<-1;
        return 0;
      }
      for (int j = busca; j>i; j--) {
      char aux = s[j];
      s[j] = s[j-1];
      s[j-1] = aux;
      pos.pb(j);
      //printArr(s, n);
     // cout<<": "<<j<<endl;
      }
    }

  }

  cout<<pos.size()<<endl;
  for(int i=0; i<pos.size(); i++){
    cout<<pos[i]<<" ";
  }
  cout<<endl;

}