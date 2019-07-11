#include <iostream>
#include <vector>
using namespace std; 

int main() {
  int j1, j2; 
  cin>>j1;

  int pel;
  bool flag = false;
  int coincidentes = 0; 


  int dias1[1000000];
  for(int i=0; i<1000000; i++){
    dias1[i] = 0;
  }

  
  //vector <int> pel1;
  for(int i=0; i<j1; i++){
    cin>>pel;
    dias1[pel]++;
    //pel1.push_back(pel);
  }

  cin>>j2;
  int dias2[1000000];

  for(int i=0; i<1000000; i++){
    dias2[i] = 0;
  }

  //vector <int> pel2;
  for(int i=0; i<j2; i++){
    cin>>pel;
    //pel2.push_back(pel);
    dias2[pel]++;
  }

    bool peliculas1 = true;
    bool peliculas2 = true;


    for(int i = 0; i < 1000000; i++) {
        if(dias1[i]==1 && dias2[i]==1) {
            peliculas1 = true;
            peliculas2 = true;
            coincidentes++;
        }
        else if(dias1[i]==1 && peliculas2) {
            peliculas1 = true;
            peliculas2 = false;
            coincidentes++;
        }
        else if(dias2[i]==1 && peliculas1) {
            peliculas1 = false;
            peliculas2 = true;
            coincidentes++;
        }
    }
  cout<<coincidentes;

}