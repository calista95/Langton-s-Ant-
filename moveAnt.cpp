/*******************************************************************************File: moveAnt.cpp
Name: Calista Wong 
Description: This file contains the implementation file for the moveAnt function. It assigns the ant to its new spot depending on the direction it is facing. The, it reassigns the color of the spot that it previously was on. For every move, the board is printed to keep track of where the ant is. 
******************************************************************************/
#include <iostream>
#include "antClass.hpp"
using namespace std;

void Ant::moveAnt()
 {
   //move ant based on current orientation
      switch (direction)
       {
        //FIRST CASE
        case 'N': 
         if (spaceColor == "white")
          {
           direction = 'E';
           myBoard[x][y] = '#';
           y = y+1;
           if (y>(columns-1))
            {
             y=0;
            }
          }
         if (spaceColor == "black")
          {
           direction = 'W';
           myBoard[x][y] = ' ';
           y = y-1;
           //wrap ant around the other side if out of bounds
           if (y<0)
            {
             y=(columns-1);
            }
          }

         if (myBoard[x][y] == ' ')
          {
           spaceColor = "white";
          } 
         if (myBoard[x][y] == '#')
          {
           spaceColor = "black";
          }
         //assign ant's new location
         myBoard[x][y] = '*';
         break;

        //SECOND CASE
        case 'S':
         if (spaceColor == "white")
          {
           direction = 'W';
           myBoard[x][y] = '#';
           y = y-1;
           if (y<0)//wrap ant around the other side if out of bounds 
            {
             y=(columns-1);
            }
          }    
         if (spaceColor == "black")
          {
           direction = 'E';
           myBoard[x][y] = ' ';
           y = y+1;
           if (y>columns-1)
            {
             y=0;
            }
          }

         if (myBoard[x][y] == ' ')
          {
           spaceColor = "white";
          }
         if (myBoard[x][y] == '#')
          {
           spaceColor = "black";
          }
         //assign ant's new location
         myBoard[x][y] = '*';
         break;

                                                                                                               //THIRD CASE
        case 'E':  
         if (spaceColor == "white")
          {
           direction = 'S';
           myBoard[x][y] = '#';
           x = x+1;
           if (x>(rows-1))//wrap ant around the other side if out of bounds
            {
             x=0;
            }
          }    
         if (spaceColor == "black")
          {
           direction = 'N';
           myBoard[x][y] = ' ';
           x = x-1;
           if (x<0)
            {
             x=(rows-1); 
            }
          }

         if (myBoard[x][y] == ' ')
          {
           spaceColor = "white";
          }
         if (myBoard[x][y] == '#')
          {
           spaceColor = "black";
          }
         //assign ant's new location
         myBoard[x][y] = '*';
         break;

        //FOURTH CASE
        case 'W':  
         if (spaceColor == "white")
          {
           direction = 'N';
           myBoard[x][y] = '#';
           x= x-1;
           if (x<0)//wrap ant around the otherside if out of bounds
            {
             x=(rows-1);
            }    
          }
        if (spaceColor == "black")
         {
          direction = 'S';
          myBoard[x][y] = ' ';
          x=x+1;
          if (x>(rows-1))
           {
            x=0;
           }
         }
 
       //change row, column unchanged
       if (myBoard[x][y] == ' ')
        {
         spaceColor = "white";
        }
       if (myBoard[x][y] == '#')
        {
         spaceColor = "black";
        }
       //assign ant's new location
       myBoard[x][y] = '*';
       break;
    }
  }
