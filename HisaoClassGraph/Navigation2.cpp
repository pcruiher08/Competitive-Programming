/*
Navigation.cpp - Library to Navigate the Maze
Created by Jaime Hisao Yesaki,  February 20, 2019.
*/

#include "Arduino.h"
#include "Navigation.h"
#include "Control.h"
#include "Tile.h"

//Declares Control Class
Control control;


//Default Constructor
Navigation::Navigation(){
  this->starterTile = NULL;
  starterTile->setLeftTo();
  starterTile;
}

int Navigation::getOrientation(){
  return _orientation;
}

void Navigation::setOrientation(int ori){
  _orientation = ori;
}

void Navigation::addToOrientation(){
  _orientation++;
}





