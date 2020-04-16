// Interface.h 
// Includes asking the user for an input, converting this into the coorisponding matrix value
// and checking if the value entered is valid.
//#########################################################################################
#include <iostream>
#include "Board.h"
#include "stdafx.h"


class Interface
{


	int letterToColumn(std::string letter);
	int NumberToRow(int Row);
	int playGame()
	

public: 
	int convMatrix()


int Interface::playGame()
{
	system("cls");  // Clears the screen
	Board = board1;
	Position startPos;
	Position endPos;
	POI_Colour = 

	cout << "Starting game" << endl;
	board1.printBoard();  // Print starting board from Harrys class
	cout << "________________________________________" << endl;
	cout << endl;


int Interface::convMatrix()
{
	//Convert input to matrix coordinates that can be used by program
	startColumn = letterToColumn(startPos.substr(0, 1));  // takes the column (char) of the input 
	startRow = NumberToRow(startPos.substr(1, 2))          // takes the row (int) of the input
		
	return (startColumn,startRow)
}
//letterToColumn converts the first character of the users input, a letter, to the 
//corresponding column. For example, if A8 is the input, this will be converted to 0,0
//#########################################################################################
int Interface::letterToColumn(const std::string letter)
{
	if	(letter == "a") { return 0; }
	else if (letter == "b") { return 1; }
	else if (letter == "c") { return 2; }
	else if (letter == "d") { return 3; }
	else if (letter == "e") { return 4; }
	else if (letter == "f") { return 5; }
	else if (letter == "g") { return 6; }
	else if (letter == "h") { return 7; }

}


//NumberToRow converts the row in integer form input by the program, to the matrix coordinates 
//for example, if A8 is the input, this will be converted to 0,0
//#########################################################################################
int Interface::NumberToRow(const int Row)
{
	if	(Row == 1) { return 7; }
	else if (Row == 2) { return 6; }
	else if (Row == 3) { return 5; }
	else if (Row == 4) { return 4; }
	else if (Row == 5) { return 3; }
	else if (Row == 6) { return 2; }
	else if (Row == 7) { return 1; }
	else if (Row == 8) { return 0; }
}
