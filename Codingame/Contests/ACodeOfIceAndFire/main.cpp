#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <chrono>
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Mine{
    public:
        Mine();
        Mine(int, int);
        int x; 
        int y;
}; 

Mine::Mine(){
    x = 0; 
    y = 0; 
}

Mine::Mine(int x, int y){
    this->x = x;
    this->y = y; 
}

class Player{
    public:
        Player();
        Player(int, int, int);
        int id; 
        int x; 
        int y;
        int numberOfUnits;
        int numberOfBuildings;
        int gold; 
        int income;
        void setGold(int);
};

void Player::setGold(int gold){this->gold = gold;}

Player::Player(){
    id = 0; 
    x = 0; 
    y = 0; 
    numberOfUnits = 0;  
    numberOfBuildings = 0;
    gold = 0; 
    income = 0;
}

Player::Player(int x, int y, int id){
    this->x = x; 
    this->y = y; 
    this->id = id;
    gold = 0; 
    income = 0;
}


class Tile{
    Tile();
    Tile(int, int, char);
    char type;
    int x; 
    int y;
};

Tile::Tile(){
    this -> x = 0;
    this -> y = 0;
    this -> type = ' ';
}

Tile::Tile(int x, int y, char type){
    this -> x = x;
    this -> y = y;
    this -> type = type;
}

Player player(); 
Player enemy();
Tile Map[12][12];
int main(){

 
    int numberMineSpots;
    cin >> numberMineSpots;
    vector<Mine> mines;
    for (int i = 0; i < numberMineSpots; i++) {
        int x;
        int y;
        cin >> x >> y;
        Mine auxMine(x,y);
        mines.push_back(auxMine);
    }

    // game loop

    while (1) {
        int gold;
        cin >> gold;
        int income;
        cin >> income;
        player.gold = gold; 
        cout<<player.gold;
        player.income = income;

        int opponentGold;
        cin >> opponentGold;
        int opponentIncome;
        cin >> opponentIncome;

        enemy.gold = opponentGold;
        enemy.income = opponentIncome;

        for (int i = 0; i < 12; i++) {
            string line;
            cin >> line;
        }
        int buildingCount;
        cin >> buildingCount;
        for (int i = 0; i < buildingCount; i++){
            int owner;
            int buildingType;
            int x;
            int y;
            cin >> owner >> buildingType >> x >> y;
        }
        int unitCount;
        cin >> unitCount;
        for (int i = 0; i < unitCount; i++) {
            int owner;
            int unitId;
            int level;
            int x;
            int y;
            cin >> owner >> unitId >> level >> x >> y;
        }


        cout << "WAIT" << endl;
    }
}