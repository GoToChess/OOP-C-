// B00713696
// Jack McErlean
// Computer player header file

#include "Rules.h"


class cpu
{
private:
	int r1, r2, r3, r4;
	char param1;
	Rules o;

public:
	// easy diffculty
	void easy_diff(Piece Matrix[8][8]);

	// hard diffculty
	void hard_diff(Piece Matrix[8][8]);
};







void cpu::easy_diff(Piece Matrix[8][8])
{
	srand(time(0));

	//if not true, will run through loop again with different random numbers
	while (1)
	{
		//Random number generator
		r1 = rand() % 8;
		r2 = rand() % 8;
		r3 = rand() % 8;
		r4 = rand() % 8;

		cout << "R1: " << r1 << endl;
		cout << "R2: " << r2 << endl;
		cout << "R3: " << r3 << endl;
		cout << "R4: " << r4 << endl;

		//getting colour of object at board co-ordinates
		param1 = Matrix[r1][r2].getColour();

		//if colour is white (computer colour)
		if (param1 == 'W')
		{
			//check if move is legal
			if (o.moveLegal(r1, r2, r3, r4, board))
			{
				cout << "Board move legal" << endl;
				//if True, moves object from source to destination
				Matrix[r3][r4] = Matrix[r1][r2];

				//changes the object colour and type to none
				Matrix[r1][r2] = piece5;

				//Check for showing source piece is wiped of original values 
				//and destination piece now has its old values
				cout << "Source Colour: " << Matrix[r1][r2].getColour() << "\t";
				cout << "Source Type: " << Matrix[r1][r2].getType() << endl;
				cout << "Destination Colour: " << Matrix[r3][r4].getColour() << "\t";
				cout << "Destination Type: " << Matrix[r3][r4].getType() << endl;

				break;

			}

		}
	}

}

void cpu ::hard_diff(Piece Matrix[8][8])
{

}


