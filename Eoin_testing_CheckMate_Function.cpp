/**
* This includes the testing for the King Situation class which holds the CheckMate function
*
*@author Eoin Durkin <durkin-e@ulster.ac.uk>
*@license http://www.gnu.org/copyleft/gpl.html
*@copyright Eoin Durkin 2020
*
*/

#include "Rules.h"
#include "Piece.h"
#include <iostream>
#include "CheckMate.h"

void print_board(Piece Matrix[8][8]);


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
//Ruairi had a similar testing code to test his Piece and Rules class so I used his template for the piece layout that and made changes 
//were necessary to test the checkmate function as shown below


//============================THIS Main Function is used test the CheckMate fucntion in the KING SITUATION CLASS======================
//different boards are created to test different scenarios
/**
*@author Ruairi Caldwell
*
*Configures each piece to a different type and colour
*
*/
int main()
{
	//creating one of each type of piece
	Piece piece1('W', 'R'), piece2('W', 'B'), piece3('W', 'N'), piece4('W', 'Q'), piece5('W', 'K'), piece6('W', 'P');
	Piece piece7('_', '_');
	Piece piece9('B', 'R'), piece10('B', 'B'), piece11('B', 'N'), piece12('B', 'Q'), piece13('B', 'K'), piece8('B', 'P');

	Piece boardCheck[8][8] = { { piece9, piece8, piece11, piece12, piece5, piece11, piece10, piece7 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece13, piece7, piece7, piece7, piece8, piece7, piece6, piece6 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece6, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece6, piece6 },
	{ piece6, piece6, piece6, piece6, piece6, piece2, piece6, piece6 },
	{ piece1, piece2, piece3, piece4, piece7, piece7, piece3, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================TESTING CheckMate FUNCTION=================" << std::endl;
	CheckMate King;
	print_board(boardCheck);
	//TESTING
	//This test will show the White King being CheckMate and Black King not being CheckMate
	//Checking if Black King is CheckMate(Yes = Return 1, No = Return = 0)
	std::cout << "Is Black King in CheckMate? (Negative Test)   :" << King.checkMate_B('B', 'W', boardCheck) << std::endl;	
	//Checking if White King is CheckMate(Yes = Return 1, No = Return = 0)
	std::cout << "Is White King in CheckMate?  (positive test)   :" << King.checkMate_W('W', 'B', boardCheck) << std::endl;

	Piece boardCheck2[8][8] = { { piece9, piece8, piece11, piece12, piece7, piece11, piece10, piece7 },
	{ piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
	{ piece7, piece13, piece7, piece7, piece7, piece7, piece7, piece7 },
	{ piece6, piece7, piece7, piece7, piece8, piece7, piece6, piece6 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece6, piece7 },
	{ piece7, piece7, piece7, piece7, piece7, piece7, piece6, piece6 },
	{ piece6, piece6, piece6, piece6, piece6, piece2, piece6, piece6 },
	{ piece1, piece2, piece3, piece4, piece5, piece7, piece3, piece1 } };
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "======================TESTING CheckMate FUNCTION=================" << std::endl;
	CheckMate King2;
	print_board(boardCheck2);
	//TESTING
	//This test will show the Black King being CheckMate and White King not being CheckMate
	//Checking if Black King is CheckMate(Yes = Return 1, No = Return = 0)
	std::cout << "Is Black King in CheckMate? (Poitive Test)   :" << King2.checkMate_B('B', 'W', boardCheck2) << std::endl;
	//Checking if White King is CheckMate(Yes = Return 1, No = Return = 0)
	std::cout << "Is White King in CheckMate?  (Negative test)   :" << King2.checkMate_W('W', 'B', boardCheck2) << std::endl;
	return 0;
}