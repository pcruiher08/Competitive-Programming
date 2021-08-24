#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define PI 3.1415926535897932384626433832795028841971
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

int initialMissionaries = 3;
int initialCannibals = 3;
int boatInitialState = 1;

string actions[5] = {"1M", "1C", "1M1C", "2M", "2C"};

struct node{
    int state[3]; //{numberOfMissionariesOnLeftSide, numberOfCannibalsOnLeftSide, whereIsTheBoat} 
    /*
    0<=numberOfMissionariesOnLeftSide<=n
    0<=numberOfCannibalsOnLeftSide<=n
    0<=whereIsTheBoat<=1, 1 for left side, 0 for right side
    */

    string action; //1M, 1C, 1M1C, 2M, 2C

    //operations 
    /*
    1M = cruza un misionero 
    1C = cruza un canibal 
    1M1C = cruza un misionero y un canibal 
    2M = cruzan dos misioneros 
    2C = cruzan dos canibales 
    */  

    int pathCostUpToThisNode; 
    vector<node*> parents;
};


bool isTransitionValid(node n, string action){

    bool whereIsTheBoat = n.state[2]; //1 for left, 0 for right
    int missionariesLeftSide = n.state[0];
    int cannibalsLeftSide = n.state[1];
    int missionariesRightSide = initialMissionaries - missionariesLeftSide;
    int cannibalsRightSide = initialCannibals - cannibalsLeftSide;

    int actions = 0;

    if(action == "1M"){
        actions = 1;
    }else if(action == "1C"){
        actions = 2;
    }else if(action == "1M1C"){
        actions = 3;
    }else if(action == "2M"){
        actions = 4;
    }else if(action == "2C"){
        actions = 5;
    }
    
    cout<<actions<<endl;

    bool enoughToMove = false;
    bool noOneWillBeEaten = false;


    switch(actions){
        case 1:
            //1M
            if(!whereIsTheBoat){//boat is on the right side
                enoughToMove = missionariesRightSide >= 1;
                noOneWillBeEaten = (missionariesRightSide - 1 >= cannibalsRightSide || missionariesRightSide == 0);
            }else{//boat is on the left side
                enoughToMove = missionariesLeftSide >= 1;
                noOneWillBeEaten = (missionariesLeftSide - 1 >= cannibalsLeftSide || missionariesLeftSide == 0);
            }

            cout<<"missR "<<missionariesRightSide << " canR "<<cannibalsRightSide<<endl;
            cout<<"missL "<<missionariesLeftSide << " canL "<<cannibalsLeftSide<<endl;

            cout<<enoughToMove<<" "<<noOneWillBeEaten<<endl;
        break;
        case 2:
            //1C
            if(!whereIsTheBoat){//boat is on the right side
                enoughToMove = cannibalsRightSide >= 1;
                noOneWillBeEaten = missionariesLeftSide >= cannibalsLeftSide + 1 || missionariesLeftSide == 0;
            }else{//boat is on the left side
                enoughToMove = cannibalsLeftSide >= 1;
                noOneWillBeEaten = missionariesRightSide >= cannibalsRightSide + 1 || missionariesRightSide == 0;
            }
        break;
        case 3:
            //1M1C
            if(!whereIsTheBoat){//boat is on the right side
                enoughToMove = missionariesRightSide >= 1 && cannibalsRightSide >= 1;
                noOneWillBeEaten = true;
            }else{//boat is on the left side
                enoughToMove = missionariesLeftSide >= 1 && cannibalsLeftSide >= 1;
                noOneWillBeEaten = true;
            }
        break;
        case 4:
            //2M
            if(!whereIsTheBoat){//boat is on the right side
                enoughToMove = missionariesRightSide >= 2;
                noOneWillBeEaten = (missionariesRightSide - 2 >= cannibalsRightSide || missionariesRightSide == 0);
            }else{//boat is on the left side
                enoughToMove = missionariesLeftSide >= 2;
                noOneWillBeEaten = (missionariesLeftSide - 2 >= cannibalsLeftSide || missionariesLeftSide == 0);
            }
        break;
        case 5:
            //2C
            if(!whereIsTheBoat){//boat is on the right side
                enoughToMove = cannibalsRightSide >= 2;
                noOneWillBeEaten = missionariesLeftSide >= cannibalsLeftSide + 2 || missionariesLeftSide == 0;
            }else{//boat is on the left side
                enoughToMove = cannibalsLeftSide >= 2;
                noOneWillBeEaten = missionariesRightSide >= cannibalsRightSide + 2 || missionariesRightSide == 0;
            }
        break;
    }

    return enoughToMove && noOneWillBeEaten;
}



vector<node*> bfs(node n){
    cout<< "("<<n.state[0]<<","<<n.state[1]<<","<<n.state[2]<<")"<<endl;

    if(n.state[0] == 0 && n.state[1] == 0 && n.state[2] == 0){
        return n.parents;
    }

    for(int i = 0; i < sizeof(actions)/sizeof(actions[0]); i++){
        
        string action = actions[i];
        cout<<i<<" "<<action<<endl;
        if(isTransitionValid(n, action)){
            node newNode;
            newNode.action = action;
            newNode.parents.push_back(&n);
            newNode.pathCostUpToThisNode = newNode.parents.size();
            newNode.state[2] = !n.state[2];
            int whereIsTheBoat = n.state[2];
            int actions = 0;

            if(action == "1M"){
                actions = 1;
            }else if(action == "1C"){
                actions = 2;
            }else if(action == "1M1C"){
                actions = 3;
            }else if(action == "2M"){
                actions = 4;
            }else if(action == "2C"){
                actions = 5;
            }

            switch(actions){
                case 1:
                    //1M
                    if(!whereIsTheBoat){//boat is on the right side
                        newNode.state[0] = n.state[0] - 1;
                    }else{//boat is on the left side
                        newNode.state[0] = n.state[0] + 1;
                    }
                break;
                case 2:
                    //1C
                    if(!whereIsTheBoat){//boat is on the right side
                        newNode.state[1] = n.state[1] - 1;
                    }else{//boat is on the left side
                        newNode.state[1] = n.state[1] + 1;
                    }
                break;
                case 3:
                    //1M1C
                    if(!whereIsTheBoat){//boat is on the right side
                        newNode.state[1] = n.state[1] - 1;
                        newNode.state[0] = n.state[0] - 1;
                    }else{//boat is on the left side
                        newNode.state[1] = n.state[1] + 1;
                        newNode.state[0] = n.state[0] + 1;
                    }
                break;
                case 4:
                    //2M
                    if(!whereIsTheBoat){//boat is on the right side
                        newNode.state[0] = n.state[0] - 2;
                    }else{//boat is on the left side
                        newNode.state[0] = n.state[0] + 2;
                    }
                break;
                case 5:
                    //2C
                    if(!whereIsTheBoat){//boat is on the right side
                        newNode.state[1] = n.state[1] - 2;
                    }else{//boat is on the left side
                        newNode.state[1] = n.state[1] + 2;
                    }
                break;
            }
        }


    }
}

int main(){
sync;

node start;
start.state[0] = initialMissionaries;
start.state[1] = initialCannibals;
start.state[2] = 1;

vector<node*> path = bfs(start);

for(int i = 0; i < path.size(); i++){
    cout<<"Paso " << i+1 << ": ("<<path[i]->state[0]<<","<<path[i]->state[1]<<","<<path[i]->state[2]<<")"<<endl;

}


return 0;
}