#include "stdafx.h"
/**
* includes all the code for TESTING the PIECE and RULES classes
*
*@author Ruairi Caldwell <caldwell-r2@ulster.ac.uk>
*@license http://www.gnu.org/copyleft/gpl.html
*@copyright Ruairi Caldwell 2020
*
*/

#include "Rules.h"
#include "Piece.h"
#include <iostream>

void print_board(Piece Matrix[8][8]);


//=============THIS MAIN FUNCTION HAS ALL THE TESTING FOR THE PIECE CLASS=================
/*int main()
{
	//testing constructor
	Piece one('W', 'R'); //white rook

	std::cout << std::endl;
	std::cout << "DEBUG: Testing getColour, getType and output functions" << std::endl;
	//testing getColour, should return 'W'
	std::cout << "The colour is: " << one.getColour() <<std::endl;
	//tesing getType,  should return 'R'
	std::cout << "The colour is: " << one.getType() << std::endl;
	//testing output function should print the colour and type
	one.output();

	//testing input function
	std::cout << std::endl;
	std::cout << "DEBUG: Attempting to convert piece to an invalid colour and type (should be unsuccessful)" << std::endl;
	one.input('T', 'T'); //should print errors as not invalid colour or type
	one.output(); //should still have original variables of 'W' and 'R'

	std::cout << std::endl;
	std::cout << "DEBUG: Changing piece to black pawn" << std::endl;
	one.input('B', 'P'); //should successfully convert the piece to a black pawn
	one.output();

	std::cout << std::endl;
	std::cout << "DEBUG: Creating a piece with no constructor parameters" << std::endl;
	Piece two;//creating a piece with not parameters which should automatically configure ('_','_')
	two.output();

	return 0;
}*/

//needed a print function that can print from any starting position which the one in the main game can't do
//jack developed this quickly to do some testing of his code and is used here to make the testing more clear

/**
*@author Jack McErlean
*
*neatly prints an array of the pieces object including both colour and type of piece
*
*@param Matrix[8][8] an 8x8 array of "Piece" objects which represent the current chess board 
*/
void print_board(Piece Matrix[8][8])
{
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			std::cout << Matrix[a][b].getColour() << Matrix[a][b].getType() << "    |";
			if (b == 7)
			{
				std::cout << std::endl;
			}
		}
	}
}


//============================THIS MAIN FUNCTION INCLUDES ALL THE TESTING FOR THE RULES CLASS======================
//different boards are created to test different scenarios
int main()
{
	//creating one of each type of piece
	Piece piece1('W', 'R'), piece2('W', 'B'), piece3('W', 'N'), piece4('W', 'Q'), piece5('W', 'K'), piece6('W', 'P');
	Piece piece7('_', '_');
	Piece piece9('B', 'R'), piece10('B', 'B'), piece11('B', 'N'), piece12('B', 'Q'), piece13('B', 'K'), piece8('B', 'P');

	std::cout << "======================INITIAL CONDITIONS OF moveLegal=================" << std::endl;
	//default chess board layout
	Piece board[8][8] = { { piece9, piece7, piece11, piece12, piece13, piece11, piece10, piece9 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece10, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece10, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece6, piece6, piece6, piece6, piece6, piece6, piece6, piece6 },
	{ piece1, piece2, piece3, piece4, piece5, piece3, piece2, piece1 } };
	
	print_board(board);
	Rules chessrules;
	//original layout chessboard
	//some base conditions of moveLegal
	//can't move a piece outside the bounds of the array
	std::cout << "attempting to move outside the bounds of the board (2, 0, 3, -1), should return 0: " << chessrules.moveLegal(2, 0, 3, -1, board) << std::endl;
	//can't move a piece to the same square
	std::cout << "can't move a piece to the same square it is on (2, 0, 2, 0), should return 0: " << chessrules.moveLegal(2, 0, 2, 0, board) << std::endl;
	//can't move a piece to  a square of the same colour
	std::cout << "can't move a piece to a square occupied by the same colour (2, 0, 4, 2) should return 0:" << chessrules.moveLegal(2, 0, 4, 2, board) << std::endl;

	Piece boardpawn[8][8] = { { piece9, piece8, piece11, piece12, piece13, piece11, piece10, piece9 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece8, piece7, piece7, piece7, piece7, piece6 },
	{ piece6, piece6, piece6, piece6, piece6, piece6, piece6, piece7 },
	{ piece1, piece2, piece3, piece4, piece5, piece3, piece2, piece1 } };


	std::cout<<std::endl;
	std::cout<<std::endl;
	std::cout << "======================PAWN TESTING=================" << std::endl;
	print_board(boardpawn);
	//TESTING 
	//can move two squares forward on starting  row only (positive test)
	std::cout << "can move two squares forward on starting  row only (positive test) (6, 0, 4, 0): " << chessrules.moveLegal(6, 0, 4, 0, boardpawn) << std::endl;
	//can move two squares forward on starting  row only (negative test)
	std::cout << "can move two squares forward on starting  row only (negative test) (5, 7, 3, 7): " << chessrules.moveLegal(5, 7, 3, 7, boardpawn) << std::endl;
	//can move one square forward only (positive test)
	std::cout << "can move one square forward only (positive test) (5, 7, 4, 7): " << chessrules.moveLegal(5, 7, 4, 7, boardpawn) << std::endl;
	//can move one square forward only (negative test)
	std::cout << "can move one square forward only (attempting to move laterally)(negative test]) (5, 7, 5, 6): " << chessrules.moveLegal(5, 7, 5, 6, boardpawn) << std::endl;
	//can only take diagonal (positive test)
	std::cout << "can only take diagonal (positive test) (6, 1, 5, 2): " << chessrules.moveLegal(6, 1, 5, 2, boardpawn) << std::endl;
	//can only take diagonal (negative test)
	std::cout << "can only take diagonal (attempting to take moving forward)(negative test) (6, 2, 5, 2): " << chessrules.moveLegal(6, 2, 5, 2, boardpawn) << std::endl;



	Piece boardrook[8][8] = { { piece9, piece8, piece11, piece12, piece13, piece11, piece10, piece9 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece9, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece6, piece6, piece6, piece6, piece6, piece6, piece6, piece7 },
	{ piece1, piece2, piece3, piece4, piece5, piece3, piece2, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================ROOK TESTING=================" << std::endl;
	print_board(boardrook);
	//TESTING 
	//can move in the lateral plane (left) (positive test)
	std::cout << "can move in the lateral plane (left) (positive test) (4, 3, 4, 0): " << chessrules.moveLegal(4, 3, 4, 0, boardrook) << std::endl;
	//can move in the lateral plane (right) (positive test)
	std::cout << "can move in the lateral plane (right) (positive test) (4, 3, 4, 4): " << chessrules.moveLegal(4, 3, 4, 4, boardrook) << std::endl;
	//can move in the medial plane (up) (positive test)
	std::cout << "can move in the medial plane (up) (positive test) (4, 3, 5, 3): " << chessrules.moveLegal(4, 3, 5, 3, boardrook) << std::endl;
	//can move in the medial plane (down) (positive test)
	std::cout << "can move in the medial plane (down) (positive test) (4, 3, 2, 3): " << chessrules.moveLegal(4, 3, 2, 3, boardrook) << std::endl;
	//cannot move diagonal (negative test)
	std::cout << "cannot move diagonal (negative test) (4, 3, 3, 2): " << chessrules.moveLegal(4, 3, 3, 2, boardrook) << std::endl;
	//cannot move randomly accross board (negative test)
	std::cout << "cannot move randomly accross board (negative test) (4, 3, 5, 7): " << chessrules.moveLegal(4, 3, 5, 7, boardrook) << std::endl;


	Piece boardbishop[8][8] = { { piece9, piece8, piece11, piece12, piece13, piece11, piece10, piece9 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece2, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece6, piece6, piece6, piece6, piece6, piece6, piece6, piece7 },
	{ piece1, piece2, piece3, piece4, piece5, piece3, piece2, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================BISHOP TESTING=================" << std::endl;
	print_board(boardbishop);
	//TESTING 
	//can move diagonally up-right (positive test)
	std::cout << "can move diagonally up-right (positive test) (3, 3, 2, 4): " << chessrules.moveLegal(3, 3, 2, 4, boardbishop) << std::endl;
	//can move diagonally up-left (positive test)
	std::cout << "can move diagonally up-left (positive test) (3, 3, 2, 2): " << chessrules.moveLegal(3, 3, 2, 2, boardbishop) << std::endl;
	//can move diagonally down-right (positive test)
	std::cout << "can move diagonally down-right (positive test) (3, 3, 5, 5): " << chessrules.moveLegal(3, 3, 5, 5, boardbishop) << std::endl;
	//can move diagonally down-left (positive test)
	std::cout << "can move diagonally down-left (positive test) (3, 3, 5, 1): " << chessrules.moveLegal(3, 3, 5, 1, boardbishop) << std::endl;
	//cannot move diagonal (negative test)
	std::cout << "illegal move  (negative test )(3, 3, 3, 5): " << chessrules.moveLegal(3, 3, 3, 5, boardbishop) << std::endl;
	//cannot move randomly accross board(negative test)
	std::cout << "illegal move (negative test) (3, 3, 5, 7): " << chessrules.moveLegal(3, 3, 5, 7, boardbishop) << std::endl;



	Piece boardqueen[8][8] = { { piece9, piece8, piece11, piece12, piece13, piece11, piece10, piece9 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece12, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece6, piece6, piece6, piece6, piece6, piece6, piece6, piece7 },
	{ piece1, piece2, piece3, piece4, piece5, piece3, piece2, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================QUEEN TESTING=================" << std::endl;
	print_board(boardqueen);
	//TESTING 
	//queen function just  OR's the bishop and rook function so as they are already tested this doesn't require much testing
	//can move diagonally up-right (positive test)
	std::cout << "By testing the bishop and rook functions this function is also effectively tested" << std::endl;
	std::cout << "can move diagonally up-right (positive test) (3, 3, 2, 4): " << chessrules.moveLegal(3, 3, 2, 4, boardqueen) << std::endl;
	//can move diagonally up-left (positive test)
	std::cout << "testing an illegal move (negative test) (3, 3, 5, 4) : " << chessrules.moveLegal(3, 3, 5, 4, boardqueen) << std::endl;



	Piece boardknight[8][8] = { { piece9, piece8, piece11, piece12, piece13, piece11, piece10, piece9 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece3, piece8, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece6, piece6, piece6, piece6, piece6, piece6, piece6, piece7 },
	{ piece1, piece2, piece3, piece4, piece5, piece3, piece2, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================KNIGHT TESTING=================" << std::endl;
	print_board(boardknight);
	//TESTING 
	//can move in L shape (positive)
	std::cout << "can move in L shape (positive test) (3, 3, 5, 4): " << chessrules.moveLegal(3, 3, 5, 4, boardknight) << std::endl;
	//can move over pawn (positive)
	std::cout << "can jump over other pieces (positive test) (3, 3, 4, 5): " << chessrules.moveLegal(3, 3, 4, 5, boardknight) << std::endl;
	//can't move any other way (negative)
	std::cout << "showing an illegal move (negative test) (3, 3, 4, 4): " << chessrules.moveLegal(3, 3, 4, 4, boardknight) << std::endl;


	Piece boardking[8][8] = { { piece9, piece8, piece11, piece12, piece13, piece11, piece10, piece9 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece5, piece8, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece6, piece6, piece6, piece6, piece6, piece6, piece6, piece7 },
	{ piece1, piece2, piece3, piece4, piece5, piece3, piece2, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================KING TESTING=================" << std::endl;
	print_board(boardking);
	//TESTING 
	//can move one square diagonally (positive test)
	std::cout << "can move one square diagonally (positive test) (3, 3, 4, 2): " << chessrules.moveLegal(3, 3, 4, 2, boardking) << std::endl;
	//can move straight one square (positive test)
	std::cout << "can move straight one square (positive test) (3, 3, 3, 4): " << chessrules.moveLegal(3, 3, 3, 4, boardking) << std::endl;
	//can't move more than one square (negative test)
	std::cout << "showing an illegal move (negative test) (3, 3, 0, 3): " << chessrules.moveLegal(3, 3, 0, 3, boardking) << std::endl;
	


	Piece boardcheck2[8][8] = { { piece9, piece8, piece11, piece12, piece7, piece11, piece10, piece7 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece5, piece8, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece13 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece9, piece7 },
	{ piece6, piece6, piece6, piece6, piece6, piece2, piece6, piece6 },
	{ piece1, piece2, piece3, piece4, piece7, piece7, piece3, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================moveLegal FINAL CONDITION CHECK=================" << std::endl;
	print_board(boardcheck2);
	//TESTING 
	//moving king into check (negative test)
	std::cout << "These rules would be legal if it weren't for them leaving the king in check so they are not" << std::endl;
	std::cout << "moving king into check (negative test) (3, 3, 4, 3): " << chessrules.moveLegal(3, 3, 4, 3, boardcheck2) << std::endl;
	//negative check
	std::cout << "move cnn't leave king in check (moving rook here would leave \n the king in check from the bishop )(negative test) (5, 6, 4, 6): " << chessrules.moveLegal(5, 6, 4, 6, boardcheck2) << std::endl;


	Piece boardsquareattack[8][8] = { { piece9, piece8, piece11, piece12, piece7, piece11, piece10, piece7 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece5, piece8, piece7, piece7, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece13 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece6, piece6, piece6, piece6, piece6, piece2, piece6, piece6 },
	{ piece1, piece2, piece3, piece4, piece7, piece7, piece3, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================TESTING INCHECK AND SQUAREATTACK FUNCTIONS=================" << std::endl;
	print_board(boardsquareattack);
	//TESTING 
	//moving king into check (negative test)
	std::cout << "incheck returns 1 if the king is in check and 0 otherwise" << std::endl;
	//invalid colour
	std::cout << "Entering an invalid King colour (negative test): " << chessrules.incheck('Q',boardsquareattack) << std::endl;
	//black king which is in check
	std::cout << "testing incheck on the black king (positive test): " << chessrules.incheck('B', boardsquareattack) << std::endl;
	//black king which is in check
	std::cout << "testing incheck on the white king (negative test): " << chessrules.incheck('W', boardsquareattack) << std::endl;

	std::cout << "The incheck function works by calling the squareattack function so it has indirectly been tested"<< std::endl;
	

	return 0;
}

