/**
* User Interface file that deals with the inputs from the user
*
* Asks the user for the coordinates of the piece they want to move
* and where they want to move it to.Takes this coordinateand
* converts in to matrix form.
*
* @author Eamon McGill <mcgill - e@ulster.ac.uk>
* @License http ://www.gnu.org/copyleft/gpl.html
* @copyright Eamon McGill 2020
*/
#include <string>
#include "computer.h"

class Interface
{
private:
	// column Input conversion
	int letterToColumn(std::string letter);

	// rown Input conversion 
	int NumberToRow(int Row);

	int startx, starty, endx, endy;
	char myColour;
	Rules check;


public:

	// Initial startup 
	int* userInput();

	int playergo;

	//Function to allow movelegal() to check if the user has selected the correct colour
	void movePiece(Piece Matrix[8][8]);


	// Inputs collected from user in coordinate format
	string startPos, endPos;

	// Final Array to be returned from user Input
	int* c = new int[4];
};


/**
* Gets the input from the user and converts in to array form
*
* Gets the coordinates from the user and using the conversion functions,
* changes the input into an array that can work with the rest of the program
*
*
* @return returns an array of the 4 input values. 'From' x and y location as well as the 'To' x and y location
* @see Interface::letterToColumn
* @see Interface::NumberToRow
*/

int* Interface::userInput()
{
	playergo = 1;


	cout << "________________________________________" << endl;
	cout << endl << "user's go... " << endl;
	cout << endl;

	cout << "Enter the coordinates of the piece you want to move. (eg A7)";
	cin >> startPos;
	cout << endl;
	cout << "Enter the coordinates of the location you want to move to. (eg A6)";
	cin >> endPos;
	cout << endl;

	//Convert input to matrix coordinates that can be used by program
	startx = letterToColumn(startPos.substr(0, 1));  // takes a sub string of the column (char) of the input 
	starty = NumberToRow(stoi(startPos.substr(1, 1)));  // takes a sub string of the row (converted to int) of the input

	endx = letterToColumn(endPos.substr(0, 1));  // takes a sub string of the column (char) of the input 
	endy = NumberToRow(stoi(endPos.substr(1, 1)));    // takes a sub string of the row (converted to int) of the input

	// Stores all input coordinates together as an array
	c[0] = startx;
	c[1] = starty;
	c[2] = endx;
	c[3] = endy;

	return c;
}


/**
* checks if the user has selected a piece that is theirs
*
*
* @param Piece Matrix[8][8] an 8x8 array of "Piece" objects which represent the current chess board
* @return returns True if the selected piece is the users, otherwise False
* @see Piece::getColour()
*/


void Interface::movePiece(Piece Matrix[8][8])
{

	myColour = Matrix[c[0]][c[1]].getColour();

	//check selected position is a valid piece of users colour
	if (myColour == 'W')
	{
		cout << "Can't do that, try again" << endl;
	}
	else if (check.moveLegal(c[1], c[0], c[3], c[2], Matrix))
	{
		Matrix[c[3]][c[2]] = Matrix[c[1]][c[0]]; // changing the source piece to the dest piece
		Matrix[c[1]][c[0]] = piece7; // empty space object piece
		playergo = 0; // integer to change to the computer's go
	}
}



/**
* Takes the user coordinates input and converts to corresponding array value
*
* @param
* @return newInput which is the positioon selected by the user in array formmat
*/

/*
int Interface::convArray()
{
	int convColumn;
	int convRow;
	//Convert input to matrix coordinates that can be used by program
	convColumn = letterToColumn(startPos.substr(0, 1));  // takes the column (char) of the input
	convRow = NumberToRow(startPos.substr(1, 2));         // takes the row (int) of the input
	newInput[0] = convColumn;
	newInput[1] = convRow;
	return newInput;
}
*/



/**
* Takes the letter character in the input coordinate and converts to corresponding matrix value
*
*
* @param letter
* @return The array value for the column input from user
*/
int Interface::letterToColumn(const std::string letter)
{
	if (letter == "a") { return 0; }
	else if (letter == "b") { return 1; }
	else if (letter == "c") { return 2; }
	else if (letter == "d") { return 3; }
	else if (letter == "e") { return 4; }
	else if (letter == "f") { return 5; }
	else if (letter == "g") { return 6; }
	else if (letter == "h") { return 7; }

}

/**
* Takes the row number from the input coordinates and converts to corresponding matrix value
*
*
* @param The array value for the row input from user
*/

int Interface::NumberToRow(const int Row)
{
	if (Row == 0) { return 0; }
	else if (Row == 1) { return 1; }
	else if (Row == 2) { return 2; }
	else if (Row == 3) { return 3; }
	else if (Row == 4) { return 4; }
	else if (Row == 5) { return 5; }
	else if (Row == 6) { return 6; }
	else if (Row == 7) { return 7; }
}