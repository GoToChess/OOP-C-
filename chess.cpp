#include "computer.h"

//code I've been using to test computer class
	//********************************************


int main()
{
	int difficulty;
	int userturn = 1;
	int n;

	cout << "welcome " << endl;

	cpu move1(&difficulty);
	Rules king;
	Board chess;

	while (1)
	{

		if (userturn)
		{
			chess.print_board(board);
			cout << " user's go... " << endl;
			cin >> n;
			cout << n << endl;
			system("cls");
			//run user's code

			 if(king.incheck('B', board)) // if the user's king is in check (moved into a check)
			{
				cout << "Game_over, Computer wins" << endl;
				break; // breaks while loop and main ends
			} 
			 if (king.incheck('W', board))
			 {
				 cout << "White king in checkmate" << endl;
			 }
			 userturn = 0;
		}

		if (!userturn)
		{
			//board display function here

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
			
			userturn = 1;
		}
	}
	
	return 0;
}

