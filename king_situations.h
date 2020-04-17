#pragma once
#include "computer.h"

//King Situation
//one for white king, one for black king, to print that the user is in checkmate. return 1 if true for message to be displayed and return 0 if not in check.
//4 8 for loops to check f the king can br hit
//if either king is still in check mate then return either 0 or 1 if the king is still in check then game over.

class King_Situations	
{
private:
	Rules k;
	int king_x, king_y;


public:
	int check_B(Piece Matrix[8][8]);
	int check_W(Piece Matrix[8][8]);

};

int King_Situations::check_B(Piece Matrix[8][8])
{
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {

			//if the object inside this location equals black king, then the co-ordinates are stored
			if (Matrix[a][b].getColour() == 'B') {
				if (Matrix[a][b].getType() == 'K') {
					king_x = a;
					king_y = b; // above is the co-ordinates,  king_x and king_y, of the king

					a = b = 7;
				}
			}
		}
	}

	for (int c = 0; c < 8; c++) {
		for (int d = 0; d < 8; d++) {


			if (k.moveLegal(c, d, king_x, king_y, Matrix))
			{
				cout << "Black king in checkmate" << endl;
				return 1; // function ends
			}

			else if (c == 7 && d == 7)
			{
				return 0;
			}

		}
	}
}

int King_Situations::check_W(Piece Matrix[8][8])
{
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {

			//if the object inside this location equals black king, then the co-ordinates are stored
			if (Matrix[a][b].getColour() == 'W') {
				if (Matrix[a][b].getType() == 'K') {
					king_x = a;
					king_y = b; // above is the co-ordinates,  king_x and king_y, of the king

					a = b = 7;
				}
			}
		}
	}

	for (int c = 0; c < 8; c++) {
		for (int d = 0; c < 8; c++) {

			if (k.moveLegal(c, d, king_x, king_y, Matrix))
			{
				cout << "White king in checkmate" << endl;
				return 1; // function ends
			}

			else if (c == 7 && d == 7)
			{
				return 0;
			}
		}
	}
}