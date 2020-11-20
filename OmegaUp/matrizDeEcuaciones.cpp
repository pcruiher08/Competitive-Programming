#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


int rows;
int cols;
float A[1000][1000];

void solve(){
    int max = 0; 
    while (max < rows) {
        float uno, dos;
        for(int i = 0; i < rows; i++){
            uno = A[max][max];
            dos = A[i][max] / A[max][max];
            for (int j = 0; j< cols; j++){
                if (i == max){
                    A[i][j] /= uno;
                }else{
                    A[i][j] -= A[max][j] * dos;
                }
            }
        }
        max++;
    }
}

void answer(){
    for (int i=0; i<rows; i++) {
                    cout << A[i][cols-1] << " ";
    }
    cout << endl;
}

int main(){
  cin>>rows;
  cols = rows+1;

    for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
        cin>>A[i][j];
      }
    }
    solve();
    answer();
}


