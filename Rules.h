#pragma once

#include "Piece.h"
#include <cstdlib>


class Rules
{
	//possibly add error message before each return 0, to display in terminal, what rule it's failed at
	//RULES THAT NEED CONSIDERED, EN PASSANT, PAWN PROMOTION, CASTLING 
	//private functions
	int Pawn_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8], char colour);
	int Rook_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8]);
	int Bishop_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8]);
	int Queen_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8]);
	int Knight_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8]);
	int King_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8]);
	int squareattack(int row, int column, char attacking_colour, Piece Matrix[8][8]);


public:
	//at some point moveLegal would be made private, needs to be replaced by a function that:
	//1. checks if that piece is a allowed to move in that certain way 
	//2. then moves that piece in copy of array 
	//3. then checks if that piece was moved in that way, would it leave their king in check.
	int moveLegal(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8]);
	int incheck(char kingcolour, Piece Matrix[8][8]);
};
















int Rules::incheck(char kingcolour, Piece Matrix[8][8])
{
	//returns 0 if king is not in check, and 1 if king is in check.

	int kingrow, kingcolumn;
	char opp_colour;

	if (kingcolour == 'W') opp_colour = 'B';
	else if (kingcolour == 'B') opp_colour = 'W';
	else
	{
		std::cout << "Not a valid colour, valid colours for the King are \'W\' and \'B\'" << std::endl;
		return 2;//failed
	}

	//find the king of the specified colour colour
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if ((Matrix[i][j].getColour() == kingcolour) && Matrix[i][j].getType() == 'K')
			{
				//storing location king was found
				kingrow = i;
				kingcolumn = j;
				std::cout << "king found at row" << kingrow << "and column" << kingcolumn << std::endl;
				//breakout of loop
				i = j = 7;
			}
		}
	}
	//calls the squareattack function with the king's position and the opposing colour which will be attacking it
	return squareattack(kingrow, kingcolumn, opp_colour, Matrix);


}

int Rules::squareattack(int row, int column, char attacking_colour, Piece Matrix[8][8])
{
	//return 1 if that square is "under attack" meaning a piece of attacking colour has that piece as a potential legal move on that square"
	int finished = 0;

	//looping through array
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			//if that piece is the correct colour we're looking to attack with
			if (Matrix[i][j].getColour() == attacking_colour)
			{
				//check if that piece could attack that square, returns if true
				finished = moveLegal(i, j, row, column, Matrix);
				if (finished == 1)
				{
					return finished;
				}
			}
		}
	}
	//if the entire array is looped through without returning then it must be false
	return 0;
}

int Rules::Pawn_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8], char colour)
{
	//Rules for white pawn
	//returns 1 if move is legal, 0 if illegal

	char opp_colour; //colour of opposition pieces
	int forward; //forward direction defined by which colour the piece is
	int startingrow; //starting row for pawns defined by colour also
	if (colour == 'W')
	{
		opp_colour = 'B';
		forward = -1;
		startingrow = 6;
	}
	else
	{
		opp_colour = 'W';
		forward = 1;
		startingrow = 1;
	}
	//POSSBILE TODO: EN PASSANT   

	//on starting move pawn may move 2 squares if both squares in front of it are free
	if ((sourcex == startingrow) && (destx == (sourcex + 2 * (forward))) && (desty == sourcey) && (Matrix[destx][desty].getType() == '_') && (Matrix[sourcex + forward][sourcey].getType() == '_')) return 1;

	//if pawn attempts to move forward 1 square and that square is empty then it's a legal move
	if ((destx == (sourcex + forward)) && (desty == sourcey) && (Matrix[destx][desty].getType() == '_')) return 1;

	//is legal to take an opposing piece diagonally
	if ((destx == (sourcex + forward)) && (desty == sourcey + 1 || desty == sourcey - 1) && (Matrix[destx][desty].getColour() == opp_colour)) return 1;
	return 0;

}

int Rules::Rook_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8])
{

	int x_diff = destx - sourcex;
	int y_diff = desty - sourcey;

	//must be either trying to move along a row or a column
	if (sourcex != destx && sourcey != desty) return 0;

	//moving vertically down
	if (x_diff > 0)
	{
		//std::cout << "rook moving vertically down" << std::endl;
		for (int i = sourcex + 1; i<destx; i++)
		{
			if (Matrix[i][sourcey].getType() != '_') return 0; //ensuring all squares between source and destination are empty
		}
		return 1;
	}
	//moving vertically up
	else if (x_diff < 0)
	{
		std::cout << "rook moving vertically up" << std::endl;
		for (int i = sourcex - 1; i>destx; i--)
		{
			if (Matrix[i][sourcey].getType() != '_') return 0;
		}
		return 1;
	}
	//moving horizontally to the right
	else if (y_diff > 0)
	{
		//std::cout << "rook moving horizontally to the right" << std::endl;
		for (int i = sourcey + 1; i<desty; i++)
		{
			if (Matrix[sourcex][i].getType() != '_') return 0;
		}
		return 1;
	}
	//horizontally left
	else if (y_diff < 0)
	{
		for (int i = sourcey - 1; i>desty; i--)
		{
			if (Matrix[sourcex][i].getType() != '_') return 0;
		}
		return 1;
	}
}

int Rules::Bishop_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8])
{
	int x_diff = destx - sourcex;
	int y_diff = desty - sourcey;

	//must be attempting to move diagonally (x distance == y distance)
	if (abs(x_diff) != abs(y_diff)) return 0;


	//moving diagonally down to the right
	if (x_diff > 0 && y_diff > 0)
	{
		for (int i = sourcex + 1; i < destx; i++)
		{
			if (Matrix[i][++sourcey].getType() != '_') return 0; //checking squares between source and destination are empty
		}
		return 1;
	}
	//moving down and to the left
	else if (x_diff > 0 && y_diff < 0)
	{
		for (int i = sourcex + 1; i < destx; i++)
		{
			if (Matrix[i][--sourcey].getType() != '_') return 0;
		}
		return 1;
	}
	//moving diagonally up to the left
	else if (x_diff < 0 && y_diff < 0)
	{
		for (int i = sourcex - 1; i > destx; i--)
		{
			if (Matrix[i][--sourcey].getType() != '_') return 0;
		}
		return 1;
	}
	//moving diagonally up to the right
	else if (x_diff < 0 && y_diff > 0)
	{
		for (int i = sourcex - 1; i > destx; i--)
		{
			if (Matrix[i][++sourcey].getType() != '_') return 0;
		}
		return 1;
	}
}

int Rules::Queen_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8])
{
	int diag, straight;
	diag = Bishop_rules(sourcex, sourcey, destx, desty, Matrix);
	straight = Rook_rules(sourcex, sourcey, destx, desty, Matrix);

	if (diag | straight) return 1;
	else return 0;
}

int Rules::Knight_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8])
{
	//this needs tested too 
	int x_diff_abs = abs(destx - sourcex);
	int y_diff_abs = abs(desty - sourcey);

	if ((x_diff_abs == 2 || y_diff_abs == 2) && (x_diff_abs + y_diff_abs == 3))return 1;
	else return 0;
}

int Rules::King_rules(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8])
{
	//x coordinate may be the same, one up or one down, AND y coordinate must be the same or one up or one down, if so 1 is returned
	if ((destx == sourcex || destx == sourcex-1|| destx== sourcex + 1) && (desty == sourcey || desty == sourcey - 1 || desty== sourcey+1)) return 1;
	//if that condition is not met 0 is returned
	return 0;
}


int Rules::moveLegal(int sourcex, int sourcey, int destx, int desty, Piece Matrix[8][8])
{
	//will return 1 if move is legal or 0 if move is illegal
	//need functionality to find out if the piece they are attempting to move actually belongs to them, team up with Eamon for this.

	Piece POI('_', '_'); //empty piece object
	char POI_Colour, POI_Type;

	POI = Matrix[sourcex][sourcey]; //Piece of Interest object
	POI_Colour = POI.getColour();
	POI_Type = POI.getType();

	if (POI_Colour == '_' || POI_Type == '_') return 0;
	//returns 0 if any input was outside the bounds of the array
	if (sourcex > 7 || sourcey > 7 || destx > 7 || desty > 7 || sourcex < 0 || sourcey < 0 || destx < 0 || desty < 0) return 0;
	if ((sourcex == destx) && (sourcey == desty)) return 0;//can't move a piece to the same square
														   //can't take piece of your own colour
	if ((POI_Colour == Matrix[destx][desty].getColour())) return 0;


	switch (POI_Type) {
	case 'P':
		return Pawn_rules(sourcex, sourcey, destx, desty, Matrix, POI_Colour);
		break;//break seems unneccessary due to the return statement.
	case 'R':
		return Rook_rules(sourcex, sourcey, destx, desty, Matrix);
		break;
	case 'B':
		return Bishop_rules(sourcex, sourcey, destx, desty, Matrix);
		break;
	case 'Q':
		return Queen_rules(sourcex, sourcey, destx, desty, Matrix);
		break;
	case 'N':
		return Knight_rules(sourcex, sourcey, destx, desty, Matrix);
		break;
	case 'K':
		return King_rules(sourcex, sourcey, destx, desty, Matrix);
		break;
	}

}