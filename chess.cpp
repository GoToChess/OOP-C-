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

	while (1)
	{

		if (userturn)
		{
			//board display function here
			cout << " user's go... " << endl;
			cout << " enter: ";
			cin >> n;
			cout << endl << n << endl;
			userturn = 0;
			//clc (clear terminal)
			//run user's code
			//run eoin's king situations
			// - needs to check that if the king was still in check or if the user moved into a checkmate
			// - needs to check if there's checkmate and display it
			// - an if statement like the one below will be ran if the first condition above is met
			//if(king_situations)
			//{
			//	cout << "Game over, Computer wins" << endl;
			//  break;
			//}
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

			userturn = 1;

			//clc (clear terminal)
			//run eoin's king situations
			// - needs to check that if the king was still in check or if the computer moved into a checkmate
			// - needs to check if there's checkmate and display it
			// - an if statement like the one below will be ran if the first condition above is met
			//if(king_situations)
			//{
			//	cout << "Game over, User wins" << endl;
			//  break;
			//}
		}
	}

	return 0;
}

