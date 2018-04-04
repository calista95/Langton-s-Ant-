/*******************************************************************************File: board.cpp
Name: Calista Wong
Description: This file contains the implementation file for the board function. It places the ant on the board according to the user defined coordinates, displays the ant at zero moves, then calls the moveAnt function based on how many moves are assigned. 
*******************************************************************************/
#include <iostream>
#include "antClass.hpp"
using namespace std;

void Ant::Board()
 {
   //place the ant on the board according to assigned coordinates
   myBoard[x][y] = '*'; 
        
   cout << "Move number: 0" << endl;
   //display initial board (no moves made so far)
   cout << " ";
   int i=0;
   while (i<rows)
    {
     cout << "-";
     i++;
    }
   cout << endl; 
   for (int i=0; i<rows; i++)
     {
      cout << "|";
      for (int j=0; j<columns; j++)
        {
         cout << myBoard[i][j];
        }
      cout << "|";
      cout << endl;
     }
    cout << " ";
    i=0;
    while (i<rows)
     {
      cout << "-" ;
      i++;
     }
    cout << endl;

   int j= 1;
   //send moves to moveAnt() function based on user defined number of moves
   for (i=0; i<numMoves; i++)
     {
      moveAnt();
      //print out current board
      cout << "Move number: " << j << endl;
      cout << " ";
     int i=0;
     while (i<rows)
      {
       cout << "-";
       i++;
      }
     cout << endl; 
     for (int i=0; i<rows; i++)
       {
        cout << "|";
        for (int j=0; j<columns; j++)
         {
           cout << myBoard[i][j];
         }
        cout << "|";
        cout << endl;
       }
       cout << " ";
       i=0;
       while (i<rows)
        {
         cout << "-" ;
         i++;
        }
        cout << endl;
        j++;  //increment next move
      } 
  }
