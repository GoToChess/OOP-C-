#pragma once
#include "rules.h"
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
	int checkMate_B(char kingcolour, char attacking_colour, Piece Matrix[8][8]);
	int checkMate_W(char kingcolour, char attacking_colour, Piece Matrix[8][8]);

};
/**
*@author Eoin Durkin
*
*Checks if the Black King is CheckMate
*
*@param kingcolour the colour of the king thats turn it is to play
*@param attacking_colour the colour of the piece which is attacking the king
*@param Matrix[8][8] an 8x8 array of "Piece" objects which represent the current chess board to be analysed
*@return returns a 1 if the Black King is CheckMate, Returns 0 if it is not
*/
int CheckMate::checkMate_B(char kingcolour, char attacking_colour, Piece Matrix[8][8])
{
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			//Locates where the Black King is on the Board and Stores the location of it
			if (Matrix[a][b].getColour() == 'B') {
				if (Matrix[a][b].getType() == 'K') {
					king_x = a;
					king_y = b;
				}
			}
		}
	}

	for (int c = 0; c < 8; c++) {
		for (int d = 0; d < 8; d++) {
			//Locates any other opponent pieces on the board, It checks if the Black King is in Check first, if so then checks
			//if the King has any possible moves in which he can escape from Check if not return 1;
			if ((K.incheck('B', Matrix) == 1) && (K.squareattack(king_x, king_y, 'W', Matrix) == 1)) 
				{
					return 1;//Black King is CheckMate
				}
			//If King can escape return 0
			else
				{
					return 0;//Black King is not in checkmate continue
				}
			}
		}
}
/**
*@author Eoin Durkin
*
*Checks if the White King is CheckMate
*
*@param kingcolour the colour of the king thats turn it is to play
*@param attacking_colour the colour of the piece which is attacking the king
*@param Matrix[8][8] an 8x8 array of "Piece" objects which represent the current chess board to be analysed
*@return returns a 1 if the White King is CheckMate, Returns 0 if it is not
*/
int CheckMate::checkMate_W(char kingcolour, char attacking_colour, Piece Matrix[8][8])
{
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			//Locates where the White King is on the Board and Stores the location of it
			if (Matrix[a][b].getColour() == 'W') {
				if (Matrix[a][b].getType() == 'K') {
					king_x = a;
					king_y = b;
				}
			}
		}
	}
	
	for (int c = 0; c < 8; c++) {
		for (int d = 0; d < 8; d++) {
			//Locates any other opponent pieces on the board, It checks if the White King is in Check first, if so then checks
			//if the King has any possible moves in which he can escape from Check if not return 1;
			if ((K.incheck('W',Matrix) == 1) && (K.squareattack(king_x, king_y, 'B', Matrix)== 1))
			{
				return 1;//White King is CheckMate
			}
			//If King can escape return 0
			else
			{
				return 0;//White King is not CheckMate
			}
		}
	}
}