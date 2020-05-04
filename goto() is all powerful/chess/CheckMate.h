#pragma once
#include "Rules.h"
/**
*Class Class Defining the king situatiosn throughout the game
*
*@author Eoin Durkin <durkin-e@ulster.ac.uk>
*@license http://www.gnu.org/copyleft/gpl.html
*@copyright Eoin Durkin 2020
*
*/

class CheckMate
{
private:
	Rules K;
	int king_x, king_y;


public:
	int checkMate(char kingcolour, Piece Matrix[8][8]);

};
/**
*@author Eoin Durkin
*
*Checks if the King is CheckMate
*
*@param kingcolour the colour of the king thats turn it is to play
*@param Matrix[8][8] an 8x8 array of "Piece" objects which represent the current chess board to be analysed
*@return returns a 1 if the King is in CheckMate, Returns 0 if it is not
*/

int CheckMate::checkMate(char kingcolour, Piece Matrix[8][8])
{
	int king_x = 0, king_y = 0;
	//find king
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Matrix[i][j].getColour() == kingcolour && Matrix[i][j].getType() == 'K')
			{
				king_x = i;
				king_y = j;
			}
		}
	}

	//check if he is allowed to move to any square around him
	int a = K.moveLegal(king_x, king_y, king_x + 1, king_y, Matrix);
	int b = K.moveLegal(king_x, king_y, king_x + 1, king_y + 1, Matrix);
	int c = K.moveLegal(king_x, king_y, king_x + 1, king_y - 1, Matrix);

	int d = K.moveLegal(king_x, king_y, king_x, king_y - 1, Matrix);
	int e = K.moveLegal(king_x, king_y, king_x, king_y + 1, Matrix);

	int f = K.moveLegal(king_x, king_y, king_x - 1, king_y - 1, Matrix);
	int g = K.moveLegal(king_x, king_y, king_x - 1, king_y, Matrix);
	int h = K.moveLegal(king_x, king_y, king_x - 1, king_y + 1, Matrix);


	//if he can't move to any square around him & he is also in check, that is checkmate
		if ((a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0) && (K.incheck(kingcolour, Matrix) == 1)) 
			return 1;
		else 
			return 0;


}