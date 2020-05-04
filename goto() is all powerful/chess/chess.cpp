#include "user.h"

/* Header Files Layout
 Piece.h -> Board.h -> rules.h -> situations.h -> computer.h -> user.h 
 ctdlib, iostream and using namespace std have all been added to the pieces class*/

 /**
 * @author Jack McErlean <mcerlean-j@ulster.ac.uk>
 * B00713696
 * Main Terminal
 *
 * objects from all our classes are made
 * constant while loop running with a state changer for who's go it is
 * while loop ended by a checkmate for user or computer
 * 
 * @return 0 for exit of function
 */
int main()
{
	int difficulty;
	int userturn = 1;

	Interface move;
	move.printLogo();

	cpu move1(&difficulty);
	Rules king;
	situations piece;
	Board chess;


	while (1)
	{

		if (userturn)
		{
			if (piece.checkMate('B', board)) // user's king is in checkmate... game over
			{
				break; // breaks while loop and main ends
			}

			chess.printBoard(board);
			move.userInput();
			move.movePiece(board);
	

			system("cls");

			 if (king.incheck('W', board))
			 {
				 cout << "White king in check" << endl;
			 }

			 piece.pawn_promotion(board);
			 
			 if (move.playergo == 0)
			 {
				 userturn = 0;
			 }
		}

		if (!userturn)
		{
			cout << "----------------- user's go over ------------------" << endl << endl;

			if (piece.checkMate('W', board)) // computer's king is in checkmate... game over
			{
				break; // breaks while loop and main ends
			}
			chess.printBoard(board);
			cout << "Computer's go... " << endl;

			if (difficulty == 1)
			{
				move1.easy_diff(board);
			}

			if (difficulty == 2)
			{
				move1.med_diff(board);
			}

			if (difficulty == 3)
			{
				move1.hard_diff(board);
			}
			if (king.incheck('W', board))
			{
				cout << " Game over, User wins" << endl;
				break;
			}

			if (king.incheck('B', board))
			{
				cout << "Black king in check" << endl;
			}

			piece.pawn_promotion(board);
			
			userturn = 1;
		}
	}
	
	return 0;
}

