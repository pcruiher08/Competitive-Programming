#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//unfinished

string blockRobotI(int x, int y, char board[10][19]){
    for(int i=0; i<10; i++){
        for(int j=0; j<19; j++){
            if(isnumber(board[i][j])){
                if(board[(i+1)%10][j]=='.' and board[(i-1)%10][j]=='.' ){

                }
            }
        }
    }
}

int main(){
    char board[10][19];
    for (int i = 0; i < 10; i++) {
        string line;
        getline(cin, line);
        for(int j=0; j<19; j++){
            board[i][j] = line[j];
        }
    }

    int robotCount;
    cin >> robotCount; cin.ignore();
    for (int i = 0; i < robotCount; i++) {
        int x;
        int y;
        string direction;
        cin >> x >> y >> direction; cin.ignore();
        char numberOfRobot = i; 
        board[x+1][y-1] = i+48;
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<19; j++){
            cerr<<board[i][j]<<" ";
        }cerr<<endl;
    }



    

    //cout << "0 0 U 1 1 R 2 2 D 3 3 L" << endl;
}