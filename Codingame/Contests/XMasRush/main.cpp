#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item{
    public:
        Item();
        Item(string name);
        string name;
        int x;
        int y;
        int from;
};

Item::Item(){
    x = 0;
    y = 0;
    from = -1;
    name = "";
}

Item::Item(string name){
    x = 0;
    y = 0;
    from = -1;
    this->name = name;
}



class Player{
    public:
        Player();
        Player(int a);
        bool isPlayer; 
        bool isOpponent;
        int x; 
        int y;
        int cards;
        int howManyItems = items.size();
        int itemToBeFound(string);
        vector<string> quests;
        vector<Item> items;
};
    Player::Player(){
        isPlayer = false; 
        isOpponent = false;
    }

    int Player::itemToBeFound(string s){
        for(int i=0; i<howManyItems; i++){
            if(items[i].name==s){
                return i;
            }
        }
        return -1;
    }

    Player::Player(int a){
        if(a==1){
            isPlayer = true;
            isOpponent = false;
        }else{
            isPlayer = false;
            isOpponent = true;
        }
    }

class Tile{
public:
    Tile();
    Tile(string data);
    void setPlayer(bool);
    void setItem(bool);
    void setOpponent(bool);
    bool isPlayerOn, isItemOn, isOpponentOn;
    string symbol;
private:
    bool hasUp, hasRight, hasLeft, hasDown;

};

Tile::Tile(){
    hasUp=false;
    hasRight=false;
    hasLeft=false;
    hasDown=false;
    isPlayerOn = false;
    isOpponentOn = false;
    isItemOn = false;
    symbol = " ";
}

Tile::Tile(string data){
    hasUp=false;
    hasRight=false;
    hasLeft=false;
    hasDown=false;
    if(data[0]=='1') hasUp = true;
    if(data[1]=='1') hasRight = true;
    if(data[2]=='1') hasDown = true;
    if(data[3]=='1') hasLeft = true;
    isPlayerOn = false;
    isItemOn = false;
    if(hasUp&&hasDown) symbol = "┃";
    if(hasRight&&hasLeft) symbol = "━";
    if(hasUp&&hasRight) symbol = "┗";
    if(hasDown&&hasRight) symbol ="┏";
    if(hasLeft&&hasDown) symbol = "┓";
    if(hasUp&&hasLeft) symbol = "┛";
    if(hasUp&&hasRight&&hasDown) symbol = "┣";
    if(hasUp&&hasDown&&hasLeft) symbol = "┫";
    if(hasLeft&&hasRight&&hasDown) symbol = "┳";
    if(hasLeft&&hasRight&&hasUp) symbol = "┻";
}

void Tile::setPlayer(bool b){
    isPlayerOn = b;
    if(isPlayerOn) symbol = "⛹";
    if(isItemOn&&isPlayerOn) symbol="✅";
}

void Tile::setOpponent(bool b){
    isOpponentOn = b;
    if(isOpponentOn) symbol = "⛹";
}

void Tile::setItem(bool b){
    isItemOn = b;
    if(isItemOn) symbol = "*";
    //if(!isItemOn) symbol = " ";
    if(isItemOn&&isPlayerOn) symbol="✅";
}
/**
 * Help the Christmas elves fetch presents in a magical labyrinth!
 **/
Tile board[7][7];
Player player, opponent;

void play(int turnType){
if(!turnType){
    //cout << "PUSH 3 RIGHT" << endl; // PUSH <id> <direction> | MOVE <direction> | PASS
    while(player.itemToBeFound(player.quests[0]) == -1){
        //player.quests.erase(player.quests.begin());
    }
    for(int i=0; i<player.howManyItems; i++){
        cerr<<player.items[i].name<<" ";
    }cerr<<endl;
    int itemToLookFor = player.itemToBeFound(player.quests[0]);
        if(player.items[itemToLookFor].y!=-1){
            if(player.items[itemToLookFor].y==0&&player.x!=player.items[itemToLookFor].x){
                cout<<"PUSH "<<player.items[itemToLookFor].x<<" UP"<<endl;
            }else if(player.items[itemToLookFor].y==6&&player.x!=player.items[itemToLookFor].x){
                cout<<"PUSH "<<player.items[itemToLookFor].x<<" DOWN"<<endl;
            }else if(player.items[itemToLookFor].x==0&&player.y!=player.items[itemToLookFor].y){
                cout<<"PUSH "<<player.items[itemToLookFor].y<<" LEFT"<<endl;
            }else if(player.items[itemToLookFor].x==6&&player.y!=player.items[itemToLookFor].y){
                cout<<"PUSH "<<player.items[itemToLookFor].y<<" RIGHT"<<endl;
            }else{
                cout<<"PUSH "<<player.items[itemToLookFor].y<<" LEFT"<<endl;
            }
        }else{
            if(player.y==0){
                cout<<"PUSH "<<player.x<<" UP"<<endl;
            }else if(player.y==6){
                cout<<"PUSH "<<player.x<<" DOWN"<<endl;
            }else if(player.x==0){
                cout<<"PUSH "<<player.y<<" LEFT"<<endl;
            }else if(player.x==6){
                cout<<"PUSH "<<player.y<<" RIGHT"<<endl;
            }else{
                cout<<"PUSH "<<player.x<<" UP"<<endl; 
            }
            //cout<<"PUSH "<<player.x<<" UP"<<endl;
        }
}else{
    //    cout<<"MOVE RIGHT UP"<<endl;
    cout<<"PASS"<<endl;
}
    
}

int main(){
    // game loop

    vector<Item> items;

    while (1) {
        int turnType;
        cin >> turnType; cin.ignore();
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                string tile;
                cin >> tile; cin.ignore();
                Tile aux(tile);
                board[i][j]=aux;
            }
        }
        for (int i = 0; i < 2; i++) {//player first, opponent second
            int numPlayerCards; // the total number of quests for a player (hidden and revealed)
            int playerX;
            int playerY;
            string playerTile;
            cin >> numPlayerCards >> playerX >> playerY >> playerTile; cin.ignore();
            Player aux(i);
            aux.x=playerX;
            aux.y=playerY;
            aux.cards = numPlayerCards;
            board[aux.y][aux.x].setPlayer(false);
            board[aux.y][aux.x].setOpponent(false);
            if(!i){
                player = aux;
                board[player.y][player.x].setPlayer(true);
            }
            else{
                opponent = aux;
                board[opponent.y][opponent.x].setOpponent(true);
            }
        
        }
        int numItems; // the total number of items available on board and on player tiles
        cin >> numItems; cin.ignore();
        player.howManyItems = numItems;
        for (int i = 0; i < numItems; i++) {
            string itemName;
            int itemX;
            int itemY;
            int itemPlayerId;
            cin >> itemName >> itemX >> itemY >> itemPlayerId; cin.ignore();
            Item aux(itemName);
            aux.x = itemX;
            aux.y = itemY;
            aux.from = itemPlayerId;
            items.push_back(aux);
            if(aux.x>0){
                board[aux.y][aux.x].setItem(true);
            }else{
                board[aux.y][aux.x].setItem(false);   
            }
            if(!itemPlayerId){
                player.items.push_back(aux);
            }else{
                opponent.items.push_back(aux);
            }
        }
        int numQuests; // the total number of revealed quests for both players
        cin >> numQuests; cin.ignore();
        for (int i = 0; i < numQuests; i++) {
            string questItemName;
            int questPlayerId;
            cin >> questItemName >> questPlayerId; cin.ignore();
            if(!questPlayerId){
                player.quests.push_back(questItemName);
            }else{
                opponent.quests.push_back(questItemName);
            }
        }
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                cerr<<board[i][j].symbol;
            }cerr<<endl;
        }

        play(turnType);

    }
}