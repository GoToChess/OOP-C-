#include "computer.h"
#include "interface.h"

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
			system("cls");  
			
			while (board1.getStatus() != checkmate)  // While status of the game is not checkmate
			{
				cout << userturn << "'s turn." << endl;
				cout << "Enter the coordinates of your starting position: " << endl;
				cin >> startPos;
				cout << "Enter the coordinates of where you want to move to: " << endl;
				cin >> endPos;
				
				//Convert input to matrix coordinates that can be used by program
				startColumn = letterToColumn(startPos.substr(0, 1));  // takes the column (char) of the input 
				startRow = NumberToRow(startPos.substr(1, 2))          // takes the row (int) of the input
				
					
				if (Check rules...)
				{
				board1.move(startPos, endPos);
				}
				
				if (board1.getStatus() == check)
				{
					cout << Colours[board1.getTurn()] << "'s king is in check!" << endl;
					
				}

				board1.printBoard();
				cout << "________________________________________" << endl;
			}

			// Output when checkmate is true
			if (userturn == 1)
			{
				cout << "Congratulations, YOU WIN!!!" << endl;
				cout << "------------- END OF GAME -------------" << endl;
			}
			else
			{
				cout << "Computer wins!! Better luck next time" << endl;
				cout << "------------- END OF GAME -------------" << endl;
			}
			
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

