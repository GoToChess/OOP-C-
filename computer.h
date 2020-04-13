/**
* @author Jack McErlean <mcerlean-j@ulster.ac.uk>
* B00713696
* Computer Player Header File
* @see pieces.h - to see how the pieces are made up
* @see Board.h - board of pieces is stored here
* @see Rules.h - movelegal function is called from this
*/

#include "Rules.h"


class cpu
{
private:
	int r1, r2, r3, r4;
	int state = 0; //state stops certain if and else statements from running
				  //depending on if the move is successful or not
	int x, y;
	char param1, param2, param3;
	Rules o; // object from the rules class needed to use movelegal function

public:

	//constructor
	cpu(int *diff);

	// easy diffculty
	void easy_diff(Piece Matrix[8][8]);

	// medium diffculty
	void med_diff(Piece Matrix[8][8]);

	//hard difficulty
	void hard_diff(Piece Matrix[8][8]);

	/*******************************************************/

	// checkmate_move, used when medium and hard difficulty is selected
	int checkmate_move(Piece array[8][8]);

	// if no possible checkmate, this function is called
	// in the medium difficulty function
	int blackpiece_move(Piece array[8][8]);

	// if no possible checkmate, this function is called in the hard difficulty
	int priority_move(Piece array[8][8]);

	// used in the priority_move function to reduce content of code
	void attack_move(char  move_colour, char  move_type, Piece array2[8][8]);
};

/**
* when a new cpu object is created, it immediately asks for the difficulty level
*
* @param *diff is a pointer to difficulty in the main terminal, which will be used
* to determine which difficulty function is run
*/

cpu ::cpu(int *diff)
{
	cout << "Select Computer difficulty level ('1' for easy, '2' for medium, '3' for hard): ";
	cin >> *diff;
}

/**
* ensures the piece is white, makes a random move and checks if its legal
*
* @param Piece Matrix[8][8] acts as a placeholder for the board object array
*/

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
		if(param1 == 'W')
		{

			//check if move is legal
			if (o.moveLegal(r1, r2, r3, r4, board))
			{
				cout << "Board move legal" << endl;
				//if True, moves object from source to destination
				Matrix[r3][r4] = Matrix[r1][r2];

				//changes the object colour and type to none
				Matrix[r1][r2] = piece7; // object used for an empty space

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

/**
* runs through checkmate function, if successful, the move is completed
* if unsucessful, runs through blackpiece function, if successful, move is completed
* if unsucessful, runs through easy difficulty function and move is completed
*
* @param Piece Matrix[8][8] acts as a placeholder for the board object array
*/

void cpu ::med_diff(Piece Matrix[8][8])
{
	// argument of each of these functions is just pointing to the argument of the medium_difficulty function, 
	//whatever is entered there

	if (!(checkmate_move(Matrix)))
	{
		if (!(blackpiece_move(Matrix)))
		{
			easy_diff(Matrix);
		}
	}

}

/**
* runs through checkmate function, if successful, the move is completed
* if unsucessful, runs through priority function, if successful, move is completed
* if unsucessful, runs through easy difficulty function and move is completed
*
* @param Piece Matrix[8][8] acts as a placeholder for the board object array
*/

void cpu ::hard_diff(Piece Matrix[8][8])
{
	// argument of each of these functions is just pointing to the argument of the hard_difficulty function, 
	//whatever is entered there

	if (!(checkmate_move(Matrix)))
	{
		if (!(priority_move(Matrix)))
		{
			easy_diff(Matrix);
		}
	}

}

/***********************Functions inside difficulty functions below **********************************************/

/**
* finds the king piece on the board and the co-ordinates are stored
* searches the board for all possible moves by,
* checking if the source piece is white and the move is legal first of all
* then checks if it leaves the king in check
* if check issuccessful, then the search for moves, stops and the move is ended
* if check is unsuccessful, the move is revoked and board reset.
* more moves are checked, until its got through all possible configs
*
* @param Piece array[8][8] acts as a placeholder for the board object array
* (it is pointing to the med_diff and hard_diff function parameters which is pointing to the board object array).
* @return 0 or 1, if it returns 1 the move is complete, if it returns 0, blackpiece function is carried out
*/

int cpu ::checkmate_move(Piece array[8][8]) {

	Piece revert_P('_', '_');

	//searching array for king piece
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {

			//if the object inside this location equals black king, then the co-ordinates are stored
			if (array[a][b].getColour() == 'B') {
				if (array[a][b].getType() == 'K') {
					cout << "king found " << endl;
					x = a;
					y = b;
				} // above is the co-ordinates,  x and y,  of the king
			}
		}
	}

	// searching array of all co-ordinates to see if the king can be check-mated
	// this is done this way to stop the same numbers from being picked
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {

					param1 = array[i][j].getColour();

					switch(param1)
					{
					case 'W':

							if (o.moveLegal(i, j, k, l, board) && state == 0) {

								revert_P = array[k][l]; //stores the original contents of dest piece stored

								//move carried out
								array[k][l] = array[i][j];

								//source piece made empty
								array[i][j] = piece7;

								cout << "i: " << i << "\t";
								cout << "j: " << j << "\t";
								cout << "k: " << k << "\t";
								cout << "l: " << l << endl;

								state = 1;
							}

							// check legal move for checkmate
							// if sucessful, the move previous will be kept
							if (o.moveLegal(k, l, x, y, board)) {
								i = j = k = l = 7; // for loops are ended
								cout << "checkmate from move" << endl;
								return 1; // function ends
							}

							// move carried out will be revoked
							// if checkmate is not successful
							else if (state == 1)
							{
								array[i][j] = array[k][l];
								array[k][l] = revert_P; // dest piece will be set back to what it originally was
								cout << "Reverted back" << endl;
								state = 0; // process starts again
							} 
					}	
				}
			}
		}
	}
	// if no checkmate move was found, this if statement is run
	if (!state)
	{
		cout << "No checkmate possible" << endl;
		return 0;

	}
}

/**
* searches the board for all possible moves by,
* checking if the source piece is white and the dest piece is black first of all
* then checks if the move is legal
* if check is successful, then the search for moves stops and the move is carried out
* if check is unsuccessful, the search continues for a successful move 
* more moves are checked, until its got through all possible configs
*
* @param Piece array[8][8] acts as a placeholder for the board object array
*(it is pointing to the med_diff function parameter which is pointing to the board object array).
* @return 0 or 1, if it returns 1 the move is complete, if it returns 0, easy difficulty function is carried out
*/

int cpu :: blackpiece_move(Piece array[8][8])
{
	for (int c = 0; c < 8; c++) {
		for (int d = 0; d < 8; d++) {
			for (int e = 0; e < 8; e++) {
				for (int f = 0; f < 8; f++) {

						param1 = array[c][d].getColour();
						param2 = array[e][f].getColour();

						// source piece to be white and dest piece to be black
						if (param1 == 'W' && param2 == 'B')
						{
							
							if (o.moveLegal(c, d, e, f, board)) 
							{

								array[e][f] = array[c][d];
								array[c][d] = piece7;

								cout << "c: " << c << "\t";
								cout << "d: " << d << "\t";
								cout << "e: " << e << "\t";
								cout << "f: " << f << endl;

								cout << "black piece destroyed" << endl;
								c = d = e = f = 7;

								return 1;

							}
						}
				}
			}
		}
	}

	// if no blackpiece move was found, this if statement is run
	if (!state)
	{
		cout << "No possible attack" << endl;
		return 0;
	}

}

/**
* runs attack_move function with different parameters each time
* focuses on specific black pieces in order,
* First is Queen then Bishop, Rook, Knight and last is Pawn
* checks if move was carried out or not
* if check is successful, then the search for moves stops and the move is carried out
* if check is unsuccessful, attack_move function is ran again with different parameters
* more moves are checked, until its got through all possible configs
*
* @param Piece array[8][8] acts as a placeholder for the board object array
*(it is pointing to the hard_diff function parameter which is pointing to the board object array).
* @return 0 or 1, if it returns 1 the move is complete, if it returns 0, easy difficulty function is carried out
*/

int cpu ::priority_move(Piece array[8][8])
{ 
	// so that less code is ran, i've put in the if statement of checking the state,
	// if the argument is met, it will jump out of the function early,  reducing the amount of code ran

	attack_move('B', 'Q', array);
	
	if (state)
	{
		return 1;
	}

	attack_move('B', 'B', array);
	
	if (state)
	{
		return 1;
	}

	attack_move('B', 'R', array);
	
	if (state)
	{
		return 1;
	}

	attack_move('B', 'N', array);
	
	if (state)
	{
		return 1;
	
	}
	attack_move('B', 'P', array);

	if (state)
	{
		return 1;
	}

	if (!state)
	{
		cout << "No possible attack" << endl;
		return 0;
	}
}

/**
*goes through all possible configurations on the board to see if the parameters are met and 
* if the move is legal.
* if the move is successful, the for loops stop and state = 1
* if the move is unsuccessful, another configuration is tried
* repeating until all configs are tried
*
* @param move_colour is a placeholder for a character to be entered, such as the colour of the piece
* @param move_type is a placeholder for a character to be entered, such as the type of the piece
* @param Piece array2[8][8] acts as a placeholder for the board object array
*(it is pointing to the priority_move function parameter which is pointing to the hard_diff function parameter
* which is pointing to the board object array)
*/

void cpu :: attack_move(char move_colour, char move_type, Piece array2[8][8])
{
	for (int c = 0; c < 8; c++) {
		for (int d = 0; d < 8; d++) {
			for (int e = 0; e < 8; e++) {
				for (int f = 0; f < 8; f++) {

					param1 = array2[c][d].getColour();
					param2 = array2[e][f].getColour();
					param3 = array2[e][f].getType();

					switch (param1)
					{
					case 'W':
						if (param2 == move_colour && param3 == move_type)
						{
							if (o.moveLegal(c, d, e, f, board))
							{

								array2[e][f] = array2[c][d];
								array2[c][d] = piece7;

								cout << "c: " << c << "\t";
								cout << "d: " << d << "\t";
								cout << "e: " << e << "\t";
								cout << "f: " << f << endl;

								cout << move_type <<  " destroyed" << endl;
								c = d = e = f = 7;

								state = 1;
							}



						}
					}
				}
			}
		}
	}
}