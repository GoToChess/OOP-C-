// Interface.h 
// Includes asking the user for an input, converting this into the coorisponding matrix value
// and checking if the value entered is valid.
//#########################################################################################
#include <iostream>
#include "Board.h"
#include "Rules.h"
#include "stdafx.h"


class Interface
{

	bool playTurn(int _whosTurn);
	bool validateInput(std::string input);
	int letterToColumn(std::string letter);
	int NumberToRow(int Row);
	int playGame()

public: 



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

	int counter = 0;  
	while (board1.getStatus() != checkmate)  // While status of the game is not checkmate
	{
		cout << """ checks whoevers turn it is """ << "'s turn." << endl;
		cout << "Enter the coordinates of your starting position: " << endl;
		cin >> startPos;
		cout << "Enter the coordinates of where you want to move to: " << endl;
		cin >> endPos;

		counter++;
		if (counter == 4)
		{
			system("cls");
			counter = 0;
		}
		
		board1.move(startPos, endPos);

		if (board1.getStatus() == check)
			cout << Colours[board1.getTurn()] << "'s king is in check!" << endl;

		board1.printBoard();
		cout << "________________________________________" << endl;
	}

	// Output when checkmate is true
	if (board1.getTurn() == White)
	{
		cout << "CHECKMATE! The Black player wins!" << endl;
		cout << "------------- END OF GAME -------------" << endl;
	}
	else
	{
		cout << "CHECKMATE! The White player wins!" << endl;
		cout << "------------- END OF GAME -------------" << endl;
	}
}

//check input is the right type, and then check the piece is the right type.
//Find this pieces possible moves
//#########################################################################################
bool Interface::validateInput(std::string input)
{

	inputCorrect = validateInput(startPos);
	if (inputCorrect == true) 
	{

		//Convert input to matrix coordinates that can be used by program
		startColumn = letterToColumn(startPos.substr(0, 1));  // takes the column (char) of the input 
		startRow = NumberToRow(startPos.substr(1, 2))          // takes the row (int) of the input

		//Check user has not picked an empty square
			if (board1(startRow, startColumn).getPieceOnSquare() != nullptr) 
			{

				//Check the user has picked one of their own pieces
				if (board1.getPiecePlayer(startRow, startColumn) == _whosTurn) 
				{

					//Find the pieces possible moves, making sure it can make a move
					possibleMoves = board1(startRow, startColumn).getPieceOnSquare()->getLegalmove(startRow, startColumn);
					if (possibleMoves.size() != 0) 
					{

						//The piece has moves it can make
						pieceCorrect = true;
					}
					else 
					{
						cout << "That piece cannot make any moves, please pick a different one." << endl;
					}
				}
				else
				{
					cout << "This piece does not belong to you." << endl;
				}
			}
			else 
			{
				cout << "There is no piece on that square! " << endl;
			}
	}
}


//letterToColumn converts the first character of the users input, a letter, to the 
//corresponding column. For example, if A8 is the input, this will be converted to 0,0
//#########################################################################################
int Interface::letterToColumn(const std::string letter)
{
	if		(letter == "a") { return 0; }
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
	if		(Row == 1) { return 7; }
	else if (Row == 2) { return 6; }
	else if (Row == 3) { return 5; }
	else if (Row == 4) { return 4; }
	else if (Row == 5) { return 3; }
	else if (Row == 6) { return 2; }
	else if (Row == 7) { return 1; }
	else if (Row == 8) { return 0; }
}