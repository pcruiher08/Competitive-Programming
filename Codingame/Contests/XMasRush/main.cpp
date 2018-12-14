#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <chrono>
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
        int itemToBeFound(vector<string>);
        vector<string> quests;
        vector<Item> items;
        private:
        struct point{
            int a, b, index;
        };

        int level(point);


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

    int Player::level(point p){
        if(p.a>=0&&p.a<=6&&p.b==0||p.a>=0&&p.a<=6&&p.b==6||p.b>=0&&p.b<=6&&p.a==0||p.b>=0&&p.b<=6&&p.a==6) return 1;
        if(p.a>=1&&p.a<=5&&p.b==1||p.a>=1&&p.a<=5&&p.b==5||p.b>=1&&p.b<=5&&p.a==1||p.b>=1&&p.b<=5&&p.a==5) return 2;
        if(p.a>=2&&p.a<=4&&p.b==2||p.a>=2&&p.a<=4&&p.b==4||p.b>=2&&p.b<=4&&p.a==2||p.b>=2&&p.b<=4&&p.a==4) return 3;
        if(p.a==3&&p.b==3) return 4;
        return p.a;
    }


    int Player::itemToBeFound(vector <string> quests){
        vector <point> points;
        for(int i=0; i<quests.size(); i++){
            for(int j=0; j<howManyItems; j++){
                if((items[j].name==quests[i])){
                    point aux;
                    aux.a = items[j].x;
                    aux.b = items[j].y;
                    aux.index = j;
                    points.push_back(aux);
                }
            }
        }
        if(points.size()<quests.size()){
            return -1;
        }else{
            for(int i=0; i<points.size(); i++){
                int lowerIndex = 0;
                cerr<<"lvl: "<<level(points[i])<<endl;
                if(level(points[i])<0) return points[i].a;
                for(int j=i+1; j<points.size(); j++){
                    if(level(points[i])<level(points[j])){
                        lowerIndex = j;
                    }
                }
                point aux = points[i];
                points[i] = points[lowerIndex];
                points[lowerIndex] = aux;
            }
            cerr<<"index to find (0): "<<points[0].index<<endl;
            cerr<<"index to find (1): "<<points[1].index<<endl;
            cerr<<"index to find (2): "<<points[2].index<<endl;
            return points[0].index;
        }
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
    int bfsData;
    bool bfsVisited;
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

void bfs(int y, int x, int count){
    if(x>=0&&x<=6&&y<=6&&y>=0){
        if(board[x][y].bfsVisited){
            return;
        }
        board[x][y].bfsVisited = true;
        board[x][y].bfsData = count+1;
        if(board[x][y].hasRight && board[x][y+1].hasLeft && !board[x][y+1].bfsVisited){ 
            bfs(y+1, x, count+1);
        }

        if(board[x][y].hasLeft && board[x][y-1].hasRight && !board[x][y-1].bfsVisited){
            bfs(y-1, x, count+1);
        }
        
        if(board[x][y].hasDown && board[x+1][y].hasUp && !board[x+1][y].bfsVisited){
            bfs(y, x+1, count+1);
        }
        
        if(board[x][y].hasUp && board[x-1][y].hasDown && !board[x-1][y].bfsVisited){
            bfs(y, x-1, count+1);
        }   
    }
    return;
}

vector<string> go(vector <string> vec){
    vector<string> directions;
    stack<string> aux;

    for(int i=0; i<vec.size(); i++){
        aux.push(vec[i]);
        //cerr<<"stack to vector"<<endl;
    }

    while(!aux.empty()){
        directions.push_back(aux.top());
        aux.pop();
    }

    for(int i=0; i<directions.size(); i++){
        if(directions[i]=="RIGHT"){
            directions[i]="LEFT";
            //cerr<<"RIGHT->LEFT"<<endl;
            //goto here;
        }else if(directions[i]=="LEFT"){
            directions[i]="RIGHT";
            //cerr<<"LEFT->RIGHT"<<endl;
            //goto here;
        }else if(directions[i]=="UP"){
            directions[i]="DOWN";
            //cerr<<"UP->DOWN"<<endl;
            //goto here;
        }else if(directions[i]=="DOWN"){
            directions[i]="UP";
            //goto here;
            //cerr<<"DOWN->UP"<<endl;
        }
        //here:
    }
   return directions;
}

vector<string> come(int x, int y){//i,j
    vector<string> directions;
    while(board[x][y].bfsData!=1){
        if(board[x-1][y].bfsData==board[x][y].bfsData-1){
            directions.push_back("UP");
            x--;
        }else if(board[x+1][y].bfsData==board[x][y].bfsData-1){
            directions.push_back("DOWN");
            x++;
        }else if(board[x][y-1].bfsData==board[x][y].bfsData-1){
            directions.push_back("LEFT");
            y--;
        }else if(board[x][y+1].bfsData==board[x][y].bfsData-1){
            directions.push_back("RIGHT");
            y++;
        }
    }
    return directions;
}

void play(int turnType){
if(!turnType){
    //cout << "PUSH 3 RIGHT" << endl; // PUSH <id> <direction> | MOVE <direction> | PASS
    cerr<<player.howManyItems<<endl;
    for(int i=0; i<player.howManyItems; i++){
        cerr<<player.items[i].name<<" ";
        cerr<<i<<endl;
    }cerr<<endl;
    //int itemToLookFor = player.itemToBeFound(player.quests[0]);//LOOKS FOR THE FIRST
    //cerr<<"AQUI1"<<endl;

    int itemToLookFor = player.itemToBeFound(player.quests);//LOOKS FOR CLOSEST
    //ARREGLAR AQUI if(itemToLookFor == -1) 
    //cerr<<"AQUI2"<<endl;
    int yCoord = player.items[itemToLookFor].y;
    int xCoord = player.items[itemToLookFor].x;
    if(itemToLookFor == -1||itemToLookFor == -2) yCoord = -1;
    cerr<<"(x,y) = ("<<xCoord<<","<<yCoord<<")"<<endl;
        if(yCoord!=-1){
            if(yCoord==0&&player.x!=xCoord){
                cout<<"PUSH "<<xCoord<<" UP"<<endl;
            }else if(yCoord==6&&player.x!=xCoord){
                cout<<"PUSH "<<xCoord<<" DOWN"<<endl;
            }else if(xCoord==0&&player.y!=yCoord){
                cout<<"PUSH "<<yCoord<<" LEFT"<<endl;
            }else if(xCoord==6&&player.y!=yCoord){
                cout<<"PUSH "<<yCoord<<" RIGHT"<<endl;
            }else if(xCoord<3&&player.y!=yCoord){
                cout<<"PUSH "<<yCoord<<" LEFT"<<endl;
            }else if(xCoord>3&&player.y!=yCoord){
                cout<<"PUSH "<<yCoord<<" RIGHT"<<endl;
            }else if(yCoord<3&&player.x!=xCoord){
                cout<<"PUSH "<<xCoord<<" UP"<<endl;
            }else if(yCoord>3&&player.x!=xCoord){
                cout<<"PUSH "<<xCoord<<" DOWN"<<endl;
            }else{
                //optimizar
                cout<<"PUSH "<<yCoord<<" LEFT"<<endl;
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
        }
}else{
    //cout<<"PASS"<<endl;
    //lets move randomly first with bfs
    string command = "MOVE ";
    vector <Tile> visited;
    int x = player.x; 
    int y = player.y;
    bfs(x, y, 0);

    int maxYIndex = 0, maxXIndex = 0;

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(board[i][j].bfsData>board[maxYIndex][maxXIndex].bfsData&&board[i][j].bfsData<=11){
                maxYIndex = i;
                maxXIndex = j;
            }
            cerr<<board[i][j].bfsData<<" ";
        }cerr<<endl;
    }

    vector <string> turningBack = come(maxYIndex, maxXIndex);
    vector <string> forth = go(turningBack);
    vector <string> back = turningBack;
    vector <string> directions;
    directions.insert(directions.end(), forth.begin(), forth.end());
    directions.insert(directions.end(), back.begin(), back.end());
    cerr<<"size of dir: "<<directions.size()<<endl;
    for(int i=0; i<directions.size(); i++){
        command+=directions[i];
        if(i<directions.size()-1)
        command+=" ";
    }
    if(directions.size()>0){
        cerr<<command<<endl;
        cout<<command<<endl;
    }else{
        cout<<"PASS"<<endl;    
    }

    //cout<<"MOVE"<<go(come(maxYIndex, maxXIndex))<<" "<<come(maxYIndex, maxXIndex)<<endl;
    //move to pick as many quests as I can
    //or
    //move the closest to an edge
    

}
    
}

int main(){
    sync;
    // game loop

    vector<Item> items;

    while (1) {
        auto begin = chrono::high_resolution_clock::now();
        int turnType;
        cin >> turnType;// cin.ignore();
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                string tile;
                cin >> tile;// cin.ignore();
                Tile aux(tile);
                board[i][j]=aux;
                board[i][j].bfsData = 0;
                board[i][j].bfsVisited = false;
            }
        }
        for (int i = 0; i < 2; i++) {//player first, opponent second
            int numPlayerCards; // the total number of quests for a player (hidden and revealed)
            int playerX;
            int playerY;
            string playerTile;
            cin >> numPlayerCards >> playerX >> playerY >> playerTile;// cin.ignore();
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
        cin >> numItems;// cin.ignore();
        player.howManyItems = 0;
        opponent.howManyItems = 0;
        for (int i = 0; i < numItems; i++){
            string itemName;
            int itemX;
            int itemY;
            int itemPlayerId;
            cin >> itemName >> itemX >> itemY >> itemPlayerId;// cin.ignore();
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
                player.howManyItems++;
            }else{
                opponent.items.push_back(aux);
                opponent.howManyItems++;
            }
        }
        int numQuests; // the total number of revealed quests for both players
        cin >> numQuests;// cin.ignore();
        for (int i = 0; i < numQuests; i++) {
            string questItemName;
            int questPlayerId;
            cin >> questItemName >> questPlayerId;// cin.ignore();
            if(!questPlayerId){
                player.quests.push_back(questItemName);
            }else{
                opponent.quests.push_back(questItemName);
            }
        }
        /*
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                cerr<<board[i][j].symbol;
            }cerr<<endl;
        }
        */


        play(turnType);
    auto end = chrono::high_resolution_clock::now();    
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    cerr << "TIME: " <<ms/2 << " ms"<<endl;
    }
}