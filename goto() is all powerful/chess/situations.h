#include "Board.h"

class situations
{
private:
	char colour, colour1, colour2;
	char type, type1;
	char piece_select;

public:
	void pawn_promotion(Piece Matrix[8][8]);
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

