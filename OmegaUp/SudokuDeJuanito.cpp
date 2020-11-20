#include <iostream>
using namespace std; 

bool areRowsOk(int mat[9][9]){

  int validador[9] = {0,0,0,0,0,0,0,0,0};

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      validador[mat[i][j]-1]++;
    }
    for(int k=0; k<9; k++){
      if(validador[k]>1){
        return false; 
      }
      validador[k] = 0;
    }
  }
  return true; 
}


bool areColumnsOk(int mat[9][9]){
  int validador[9] = {0,0,0,0,0,0,0,0,0};

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      validador[mat[j][i]-1]++;
    }
    for(int k=0; k<9; k++){

      if(validador[k]>1){
        return false; 
      }
      validador[k] = 0;
    }
  }
return true; 
}

bool areSectionsOk(int mat[9][9]){
  int coordinates[18] = {1,1,1,4,1,7,1,4,4,4,7,4,1,7,4,7,7,7};
  int toValidate[9];
  int validador[9] = {0,0,0,0,0,0,0,0,0};
  int count = 0; 

for(int o=0; o<9; o++){
  
    toValidate[0] = mat[coordinates[count]][coordinates[count+1]];
    toValidate[1] = mat[coordinates[count]+1][coordinates[count+1]];
    toValidate[2] = mat[coordinates[count]-1][coordinates[count+1]];
    toValidate[3] = mat[coordinates[count]][coordinates[count+1]+1];
    toValidate[4] = mat[coordinates[count]][coordinates[count+1]-1];
    toValidate[5] = mat[coordinates[count]+1][coordinates[count+1]-1];
    toValidate[6] = mat[coordinates[count]-1][coordinates[count+1]+1];
    toValidate[7] = mat[coordinates[count]+1][coordinates[count+1]+1];
    toValidate[8] = mat[coordinates[count]-1][coordinates[count+1]-1];  
    count = count+2;


/*
  for(int i=0; i<9; i++){
    cout<<toValidate[i];
  }
    cout<<endl; 
    */
    

    for(int j=0; j<9; j++){
      validador[toValidate[j]+1]++;
      toValidate[j] = 0;
    }
    for(int k=0; k<9; k++){
      if(validador[k]>1){
        return false; 
      }
      validador[k] = 0;
    }
}


return true; 
}


int main() {
  int sudoku[9][9];

  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      cin>>sudoku[i][j];
    }
  }

  if(areRowsOk(sudoku)&& areColumnsOk(sudoku)&& areSectionsOk(sudoku)){
    cout<<"Isaias resolvio el sudoku de Juanito"<<endl;
  }else{
    cout<<"El sudoku de Juanito vencio a Isaias"<<endl;
  }

}


/*
4 3 5 2 6 9 7 8 1
6 8 2 5 7 1 4 9 3
1 9 7 8 3 4 5 6 2
8 2 6 1 9 5 3 4 7
3 7 4 6 8 2 9 1 5
9 5 1 7 4 3 6 2 8
5 1 9 3 2 6 8 7 4
2 4 8 9 5 7 1 3 6
7 6 3 4 1 8 2 5 9
*/