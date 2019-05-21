#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <chrono>
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


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

class Unit{
  public:
    int owner; 
    int unitID;
    int level; 
    int x, y;
    Unit();
    Unit(int,int,int,int);
};

Unit::Unit(){
    x = 0; 
    y = 0; 
    unitID = 0; 
    level = 0;
}

Unit::Unit(int x, int y, int unitID, int level){
    this -> x = x; 
    this -> y = y;
    this -> unitID = unitID; 
    this -> level = level;
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
        void updateUnits(vector<Unit>);
};

void Player::updateUnits(vector<Unit> units){
    for(int i=0; i<units.size(); i++){
        if(units[i].owner == 0){
            numberOfUnits++;
        }
    }
}

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
    public:
        Tile();
        Tile(int x, int y, char type);
        char type;
        int x; 
        int y;
        void setX(int y){this -> y = y;};
        void setY(int x){this -> x = x;};
        void setType(char type){this -> type = type;};
        bool isVoid, isNeutral, isOwnedAndActive, isOwnedAndInactive, isOpponentAndActive, isOpponentAndInactive;
};

Tile::Tile(){
    this -> x = 0;
    this -> y = 0;
    this -> type = ' ';
    isVoid = false;
    isNeutral = false; 
    isOwnedAndActive = false;
    isOwnedAndInactive = false;
    isOpponentAndActive = false; 
    isOpponentAndInactive = false;
}

Tile::Tile(int x, int y, char type){
    this -> x = x;
    this -> y = y;
    this -> type = type;
    isVoid = false;
    isNeutral = false; 
    isOwnedAndActive = false;
    isOwnedAndInactive = false;
    isOpponentAndActive = false; 
    isOpponentAndInactive = false;
    if(type = '#') isVoid = true;
    if(type = '.') isNeutral = true;
    if(type = 'O') isOwnedAndActive = true; 
    if(type = 'o') isOwnedAndInactive = true; 
    if(type = 'X') isOpponentAndActive = true; 
    if(type = 'x') isOpponentAndInactive = true;
}
class Building{
    public:
        int x, y, owner,type;
        Building();
        Building(int,int,int,int);
};

Building::Building(){
    x = 0; 
    y = 0; 
    owner = 0; 
    type = 0;
}

Building::Building(int x, int y, int owner, int type){
    this -> x = x; 
    this -> y = y;
    this -> owner = owner; 
    this -> type = type;
}



Tile Map[12][12];
int main(){

Player *player = new Player(); 
Player *enemy = new Player();
 
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
        player->gold = gold; 
        player->income = income;

        int opponentGold;
        cin >> opponentGold;
        int opponentIncome;
        cin >> opponentIncome;

        enemy->gold = opponentGold;
        enemy->income = opponentIncome;

        for (int i = 0; i < 12; i++) {
            string line;
            cin >> line;
            int j = 0;
            for(int i=0; i<12; i++){
                //cerr<<line<<endl;
                Tile aux(i,j++,line[i]);
                Map[i][j] = aux;
                cerr<<Map[i][j].type;
            }
            cerr<<endl;
        }

        int buildingCount;
        cin >> buildingCount;
        
        vector<Building> buildings;
        for (int i = 0; i < buildingCount; i++){
            int owner;
            int buildingType;
            int x;
            int y;
            cin >> owner >> buildingType >> x >> y;
            Building aux(x,y,owner, buildingType);
            buildings.push_back(aux);
        }
        int unitCount;
        cin >> unitCount;
        vector <Unit> units;
        for (int i = 0; i < unitCount; i++) {
            int owner;
            int unitId;
            int level;
            int x;
            int y;
            cin >> owner >> unitId >> level >> x >> y;
            Unit aux(x,y,unitId, level);
            units.push_back(aux);
        }
        
        for(int i=0; i<units.size(); i++){
            cerr<<units[i].unitID<<" ";
        }cerr<<endl;


        
        if(player->numberOfUnits < 1 && player->gold >= 10){
            cout<<"TRAIN 1 0 1;"<<endl; 
        }
        if(player->numberOfUnits < 2 && player->numberOfUnits >= 1 && player->gold >= 10){
            cout<<"TRAIN 1 1 1;"<<endl; 
        }
        
        //cout << "WAIT" << endl;
    }
}