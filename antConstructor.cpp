/*******************************************************************************File: antConstructor
Name: Calista Wong 
Description: This contains the constructor for the ant class. It initializes all the user defined values to member variables. 
******************************************************************************/

#include "antClass.hpp"

Ant::Ant(char**array, int sr, int sc, int r, int c, int s, char d)
 {
  myBoard=array;
  numMoves=s;
  rows=r;
  columns=c;
  direction=d;
  x=sr;
  y=sc;
  spaceColor="white";
  moveNum=1;
 }
