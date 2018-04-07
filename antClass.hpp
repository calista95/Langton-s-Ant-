/******************************************************************************
File: antClass.hpp
Name: Calista Wong 
Description: This contains the header file for the ant class. It contains the class members and function definitions.
******************************************************************************/ 

#ifndef ANTCLASS_HPP
#define ANTCLASS_HPP
#include <iostream>
#include <string>
using namespace std;

class Ant
 {
   private:
   int rows,
       columns,
       startingRow,
       startingColumn,
       numMoves,
       x,
       y,
       moveNum; 
   char direction,
      **myBoard;
   string spaceColor; 
   
   public:
   Ant(char**, int, int, int, int, int, char);
   void Board();
   void moveAnt();
 };

#endif
