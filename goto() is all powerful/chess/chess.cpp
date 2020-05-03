#include "user.h"

/* Header Files Layout
 pieces.h -> Board.h -> situations.h -> rules.h -> computer.h -> user.h 
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

	cout << "welcome " << endl;

	cpu move1(&difficulty);
	Interface move;
	Rules king;
	situations piece;
	Board chess;


	while (1)
	{

		if (userturn)
		{
			chess.print_board(board);
			move.userInput();
			move.movePiece(board);

			system("cls");

			 if(king.incheck('B', board) && !(move.playergo)) // if the user's king is in check (moved into a check)
			 {
				cout << "Game_over, Computer wins" << endl;
				break; // breaks while loop and main ends
			 } 
			 if (king.incheck('W', board))
			 {
				 cout << "White king in checkmate" << endl;
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
				cout << "Black king in checkmate" << endl;
			}

			piece.pawn_promotion(board);
			
			userturn = 1;
		}
	}
	
	return 0;
}

