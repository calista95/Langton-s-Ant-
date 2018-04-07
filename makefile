#This is the Makefile for lab 2
#Author: Calista Wong 


output: antMain.o board.o moveAnt.o antConstructor.o
	g++ antMain.o board.o moveAnt.o antConstructor.o -o output
 

antMain.o: antMain.cpp
	g++ -c antMain.cpp

board.o: board.cpp antClass.hpp 
	g++ -c board.cpp 

moveAnt.o: moveAnt.cpp antClass.hpp
	g++ -c moveAnt.cpp 

antConstructor.o: antConstructor.cpp antClass.hpp
	g++ -c antConstructor.cpp 

clean:
	rm *.o output
	
