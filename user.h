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

using namespace std;

class Interface
{
private:
	// column Input conversion
	int letterToColumn(std::string letter);

	// rown Input conversion 
	int NumberToRow(int Row);

	// 
	int startx, starty, endx, endy;
	char myColour;
	Rules check;


public:

	// Initial startup 
	int* userInput();

	int* playergo;

	//Function to allow movelegal() to check if the user has selected the correct colour
	void movePiece(Piece Matrix[8][8]);


	// Inputs collected from user in coordinate format
	string startPos, endPos;

	// Final Array to be returned from user Input
	int* c = new int[4];

	void printLogo(void);
};


/**
* Gets the input from the user and converts in to array form
*
* Gets input from the user and checks if this input is valid. 
* Converts these input coordinates using the conversion functions and
* changes the input into an array that can work with the rest of the program
*
*
* @return returns an array of the 4 input values. 'From' x and y location as well as the 'To' x and y location
* @see Interface::letterToColumn
* @see Interface::NumberToRow
*/

int* Interface::userInput()
{

	// Creating ASCII variables for input validation between A and H
	char A = 'A';
	char H = 'H';
	int ascii_A = int(A);
	int ascii_H = int(H);



		cout << endl << "________________________________________" << endl;
		cout << endl << "user's go... " << endl;
		cout << endl;

		cout << "Enter the coordinates of the piece you want to move. (eg A1): ";
		cin >> startPos;
		cout << endl;
		cout << "Enter the coordinates of the location you want to move to. (eg A2): ";
		cin >> endPos;

	
		while(1)
		{

			char startChar = startPos[0];
			int SCascii = startChar;
			int startInt = startPos[1];
			
			char destChar = endPos[0];
			int DCascii = destChar;
			int destInt = endPos[1];
			
			// Input validation to make sure x value falls between A and H and the y is between 1 and 8
			if (!((SCascii >= ascii_A && SCascii <= ascii_H) || (startInt >= 1 && startInt <= 8)))
			{
				cout << "Your inputted move, " << startPos << ", is invalid." << endl;
				cout << "Enter the coordinates of the piece you want to move. (eg A1) : ";
				cin >> startPos;
				cout << endl;
			}

			
			else if (!((DCascii >= ascii_A && DCascii <= ascii_H) || (startInt >= 1 && startInt <= 8)))
			{
				cout << "Your inputted move, " << endPos << ", is invalid." << endl;
				cout << "Enter the coordinates of the piece you want to move. (eg A1) : ";
				cin >> startPos;
				cout << endl;
			}

			else
				break;
		}
	

		cout << endl;
		cout << "You have selected the piece at " << startPos << " and want to move it to " << endPos << endl;

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
* checks if the user has selected a legal move, if true, the piece is moved
*
* Checks if the user has seleted a colour that is theirs, and if the move they are trying
* to make is within the rules. If so the source piece is moved to the destination and 
* the source is then cleared to an empty piece. 
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
		cout << "That piece isn't the correct colour!" << endl;
	}
	else if (check.moveLegal(c[1], c[0], c[3], c[2], Matrix))
	{
		Matrix[c[3]][c[2]] = Matrix[c[1]][c[0]]; // changing the source piece to the dest piece
		Matrix[c[1]][c[0]] = piece7; // empty space object piece
		*playergo = 0; // pointer to change to the computer's go
	}
}



/**
* Takes the letter character in the input coordinate and converts to corresponding matrix value
*
*
* @param letter
* @return The array value for the column input from user
* @see Interface::NumberToRow
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
* @see Interface::letterToColumn
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



/**
* Prints out a logo for aesthetics
*
*
*/
void Interface::printLogo(void)
{
	cout << "===============================================\n";
	cout << "       _____ _    _ ______  _____ _____\n";
	cout << "      / ____| |  | |  ____|/ ____/ ____|\n";
	cout << "     | |    | |__| | |__  | (___| (___ \n";
	cout << "     | |    |  __  |  __|  \\___ \\\\___ \\ \n";
	cout << "     | |____| |  | | |____ ____) |___) |\n";
	cout << "      \\_____|_|  |_|______|_____/_____/\n\n";
	cout << "===============================================\n\n";
	cout << " Created by Ruairi, Eamon, Jack, Eoin and Harry \n";
	cout << "===============================================\n\n";
}
