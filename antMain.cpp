/*******************************************************************************
File: antMain.cpp
Name: Calista Wong 
Description: This includes the main for Langton's Ant simulation. It contains a menu for the user to decide whether to proceed with the simulation. If the user says yes, then the user will be prompted to enter the desired data. Then, it will send this data to the ant class to be interpreted. After, it will prompt the user if they want to repeat the simulation again. 
*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include "antClass.hpp"
using namespace std;

int main()
{
  int startSim;

  //prompt user to start the simulation
  cout << "Hit 1 if you want to start the simulation. Hit 2 if you want to quit." << endl;
  cin >> startSim;
  while (!cin || (startSim !=1 && startSim !=2))
   {
    cout << "Bad value. Enter another. " << endl;
    cin.clear();
    cin.ignore();
    cin >> startSim;
   } 

  while (startSim == 1)
   {
    //declare necessary variables 
    int rows,
        columns,
        numMoves,
        startingRow,
        startingColumn,
        randomStart;     
    char direction;

  //prompt user to decide whether to have a random or set starting location
  cout << "Do you want a random starting location for your ant? Press 1 for yes and 2 for no." << endl; 
  cin >> randomStart;
  while (!cin || (randomStart !=1 && randomStart !=2))
   {
    cout << "Bad value. Enter another. " << endl;
    cin.clear();
    cin.ignore();
    cin >> randomStart;
   } 

  //prompt user to enter number of rows, then verify input
  cout << "Enter the number of rows." << endl;
  cin >> rows;  
  while (!cin || rows<=0)
   {
    cout << "Bad value. Enter another. " << endl;
    cin.clear();
    cin.ignore();
    cin >> rows;
   } 

  //prompt user to enter number of columns, then verify input
  cout << "Enter the number of columns for your board. " << endl;
  cin >> columns;
  while (!cin || columns<=0)
   {
    cout << "Bad value. Enter another. " << endl;
    cin.clear();
    cin.ignore();
    cin >> columns;
   } 

  //prompt user to enter number of steps, then verify input 
  cout << "Enter the number of steps for your simulation. " << endl;
  cin >> numMoves;
  while (!cin || numMoves<0)
   {
    cout << "Bad value. Enter another. " << endl;
    cin.clear();
    cin.ignore();
    cin >> numMoves;
   } 

  //determine where the ant will start
  if (randomStart == 2) //user does not want a random start, prompt to manually enter
   {
    cout << "Enter a starting row between 0 and (row-1) ." << endl;
    cin >> startingRow;
    while (!cin || startingRow<0 || startingRow>=rows)
     {
      cout << "Bad value. Enter another. " << endl;
      cin.clear();
      cin.ignore();
      cin >> startingRow;
     } 
    cout << "Enter a starting column between 0 and (column-1)." << endl;
    cin >> startingColumn;
    while (!cin || startingColumn<0 || startingColumn>columns)
     {
      cout << "Bad value. Enter another. " << endl;
      cin.clear();
      cin.ignore();
      cin >> startingColumn;
     } 
   }
  if (randomStart == 1) // user wants a random start, assign random numbers in the range of the row and column entered  
   {
    startingRow = 0+(rand()%((rows-1)-0+1));
    startingColumn = 0+(rand()%((columns-1)-0+1));
   }

  //promt user to enter the starting direction, then verify input
  int dir;
  cout <<  "Which direction is your ant facing? Enter either 1, 2, 3, or 4 for the following choices." << endl;
  cout << "1. North" << endl;
  cout << "2. South" << endl;
  cout << "3. East" << endl;
  cout << "4. West" << endl;
  cin >> dir;

  while (!cin || dir<1 || dir>4)
   {
    cout << "Bad value. Enter another." << endl;
    cin.clear();
    cin.ignore();
    cin >> dir;
   } 

  //determine corresponding direction
  switch(dir)
    {
     case(1):
      direction = 'N';
      break; 
     case(2):
      direction = 'S';
      break;
     case(3):
      direction = 'E';
      break;
     case(4):
      direction = 'W';
      break;
    }
 
  //create an array based on the size specified
  char **myArray;
  myArray = new char*[rows];
  for (int i=0; i<rows; i++)
    {
     myArray[i] = new char[columns];
    }

  //initalize all array positions to be blank character
  for (int i=0; i<rows; i++)
   {
    for (int j=0; j<columns; j++)
     {
      myArray[i][j] = ' ';
     }
   }
 
  //display the data entered
  cout << "Data has been successfully entered as the following: " << endl;
  cout << "rows: " << rows << endl;
  cout << "columns: " << columns << endl;
  cout << "starting row: " << startingRow << endl;
  cout << "starting column: " << startingColumn << endl;
  cout << "number of moves: " << numMoves << endl;
  cout << "starting direction: " << direction << endl;


  //make an ant object, then initialize it with the user-defined values
  Ant myAnt(myArray, startingRow, startingColumn, rows, columns, numMoves, direction);
  //call the board function of the ant class 
  myAnt.Board();  

  //deallocate the memory used for the array
  for (int i=0; i<rows; i++)
    {
     delete [] myArray[i];
    }
  delete[] myArray;
  myArray = 0;

  //ask user if they want to start the simulation again, then verify choice
  cout << "Do you want to run the simulation again? Press 1 for yes, press 2 for no." << endl;
  cin >> startSim;
  
  while (!cin || dir<1 || dir>2)
   {
    cout << "Bad value. Enter another." << endl;
    cin.clear();
    cin.ignore();
    cin >> startSim;
   } 

  cout << "You have successfully quit the simulation." << endl;
 }

  return 0;
 }

