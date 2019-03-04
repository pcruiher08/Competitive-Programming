/*
  Navigation.h - Library to Navigate the Maze
  Created by Jaime Hisao Yesaki,  February 20, 2019.
*/

#ifndef Navigation_h
#define Navigation_h
#include "Tile.h"

//This class is in charge of autonomous robot movement in the field.
class Navigation {
public:

  //Constructor(s)
  Navigation(); //Default Constructor

  void findClosestNode(); //Method to find the next node in the Maze
  byte decideNextMove(bool, bool, bool); //This method decides the Next Move to do
  void scanSides(); //Once inside a Travellable Tile, it sees which are Walls and which are other Tiles;
  void adjustToNextMove(); /*The Robot will not always be facing the theoretical North,
  meaning that the robot will have to adjust depending on where it is, and so, if the robot
  is facing North, and wants to go straight it can just goStraight(), but if its facing east and wants
  to "turn left", it will have to first turn left and then go straight, thus requiring
  orientation and help in doing so.
  */

  //Movement FUNCTIONS
  void moveToNextTile();

  //Victim Scanning
  void scanForVictims();

  //Checkpoints and Home Methods
  void solveBackToHome();
  void backToHome();
  void restartToCheckpoint();

  //
  void atNewNode();

  //PENDING FUNCTIONS
  void findNearestDecisionNode(); //Method to find the nearest decision node in the Maze

  //enum orientation {north, east, west, south};

  //Setter and Getter for Orientation int 
  int getOrientation();
  void setOrientation(int);
  void addToOrientation();

  //Decision Node Checker
  bool checkIfDecisionNode();

  void starterTileInit();

private:
  bool isDone; //Stores the Maze status, true if solved, false if not
  int linkedListNodeDepth; //Stores the "depth" of the graph, which is changed as the robot travels
  Tile* starterTile;
  Tile currentTile;
  int _orientation;
  byte moveToBeMade;
  //Tile* startNode;
};

#endif
