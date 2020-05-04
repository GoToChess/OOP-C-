#include "rules.h"

class situations
{
private:
	char colour, colour1, colour2;
	char type, type1;
	char piece_select;
	Rules K;
	int king_x, king_y;

public:
	void pawn_promotion(Piece Matrix[8][8]);
	int checkMate(char kingcolour, Piece Matrix[8][8]);
};


// if pawn Black or white, reaches the opponents end, piece selection is called
void situations::pawn_promotion(Piece Matrix[8][8])
{
	for (int a = 0; a <= 7; a++)
	{
		colour = Matrix[0][a].getColour();
		type = Matrix[0][a].getType();

		if (colour == 'W' && type == 'P')
		{
			cout << "White pawn has reached promotion at  0," << a << endl;
			Matrix[0][a] = piece4;

		}
	}

	for (int b = 0; b <= 7; b++)
	{
		colour = Matrix[7][b].getColour();
		type = Matrix[7][b].getType();

		if (colour == 'B' && type == 'P')
		{
			cout << "Black pawn has reached promotion at 7," << b << endl;
			cout << "choose what piece you want, can't be a king (type the letter of the piece you want, for example 'Q'):  " << endl;
			cin >> piece_select;

			if (piece_select == 'Q')
			{
				Matrix[7][b] = piece12;
			}
			else if (piece_select == 'B')
			{
				Matrix[7][b] = piece11;
			}
			else if (piece_select == 'N')
			{
				Matrix[7][b] = piece10;
			}
			else if (piece_select == 'R')
			{
				Matrix[7][b] = piece9;
			}


		}
	}


}

int situations::checkMate(char kingcolour, Piece Matrix[8][8])
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
