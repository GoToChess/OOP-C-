// B00713696
// Jack McErlean
// Computer player header file

#include "Pieces.h"
#include "Rules.h"
//#include "board.h" 



class cpu
{
private:
	int r1, r2, r3, r4;
	char param1;

public:
	// easy diffculty
	void easy_diff(Piece** Matrix);

	// hard diffculty
	void hard_diff(Piece** Matrix);
};



void cpu::easy_diff(Piece** Matrix)
{
	srand(time(0));

	//if not true, will run through loop again with different random numbers
	while(1)
	{
		//Random number generator
		r1 = rand() % 8;
		r2 = rand() % 8;
		r3 = rand() % 8;
		r4 = rand() % 8;

		//getting colour of object at board co-ordinates
		param1 = Matrix[r1][r2].getColour();

		//if colour is white (computer colour)
		if (param1 == 'W')
		{
			//check if move is legal
			if (moveLegal(r1,r2,r3,r4, Matrix[8][8]))
			{
				//if True, moves object from source to destination
				Matrix[r3][r4] = Matrix[r1][r2];

				//changes the object colour and type to none
				Matrix[r1][r2].input('X', 'X');

				break;

			}

		}
	}
	
}

void cpu ::hard_diff(Piece** Matrix)
{

}



