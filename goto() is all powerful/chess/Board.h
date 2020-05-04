#pragma once

/**
*A header file containing board class for board display, and declaration of board layout
*
*@author Harry Hawkes <hawkes-h@ulster.ac.uk>
*@license http://www.gnu.org/copyleft/gpl.html
*@copyright Harry Hawkes 2020
*
*/

#include "Piece.h"

using namespace std;

//Creates a macros to define characters to make up white and black graphical squares 
//using ASCII characters
#define WHITESQUARES 0xDB 
#define BLACKSQUARES 0xFF 

class Board
{
    /**
    *A class that defines a chess board
    *
    *@author Harry Hawkes <hawkes-h@ulster.ac.uk>
    *
    *@function printBoard - prints the chess board to console
    *@function printRow - prints a row on the board
    *@function squarePairCreation - creates a square for each square pair on board
    *@printKey - prints a key for players to know which pieces are which
    */

private:
    //Board class variables that can be used privetly

    //ASCII Character for white and black are rectangular, squareCharSize defines a width as to make them
    //Square, 6 Characters wide.
    int squareCharSize = 6;

public:
    //Board class Functions that can be used publicly to display board
    void printBoard(Piece board[8][8]);
    void printRow(int mainRow, int firstColour, int secondColour, Piece Matrix[8][8]);
    void printKey();
    void squarePairCreation(char squareColour, int mainRow, int squarePairNum, int subLine, Piece Matrix[8][8]);

};


Piece piece1('W', 'R'), piece2('W', 'N'), piece3('W', 'B'), piece4('W', 'Q'), piece5('W', 'K'), piece6('W', 'P');
Piece piece7('_', '_');
Piece piece9('B', 'R'), piece10('B', 'N'), piece11('B', 'B'), piece12('B', 'Q'), piece13('B', 'K'), piece8('B', 'P');

Piece board[8][8] = { { piece9, piece10, piece11, piece12, piece13, piece11, piece10, piece9 },
                        { piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8 },
                        { piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
                        { piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
                        { piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
                        { piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7 },
                        { piece6, piece6, piece6, piece6, piece6, piece6, piece6, piece6 },
                        { piece1, piece2, piece3, piece4, piece5, piece3, piece2, piece1 } };
/*
void Board::print_board(Piece Matrix[8][8])
{
    for (int a = 0; a <= 7; a++)
    {
        for (int b = 0; b <= 7; b++)
        {
            cout << Matrix[a][b].getColour() << Matrix[a][b].getType() << " | ";
            if (b == 7) {
                cout << endl;
            }
        }
    }
}
*/
void Board::printBoard(Piece board[8][8])
{
    /**
    *@author Harry Hawkes <hawkes-h@ulster.ac.uk>
    *
    *Function to display a visual representation of the board
    *
    *@param matrix[8][8] - an 8x8 matrix array containing layout of the board pieces
    *@return void (nothing)
    */

    cout << "\n\n         (Computer - White Pieces)         \n\n";

    //Printing to console the letter corosponding to column of board, at top of board
    cout << "   A     B     C     D     E     F     G     H\n\n";

    //For loop to iterate through each row on board, starting at bottom of board
    for (int mainRow = 7; mainRow >= 0; mainRow--)
    {
        //Nested if/else statement to print each row
        if (mainRow % 2 == 0)
        {
            //For row starting with a black squares i.e. 0/2/4/6, runs printLine function to
            //display row, with corrosponding pieces according to 8x8 matrix
            printRow(mainRow, BLACKSQUARES, WHITESQUARES, board);
        }

        else
        {
            ////For row starting with a white squares i.e. 1/3/5/7, runs printLine function to
            //display row, with corrosponding pieces according to 8x8 matrix
            printRow(mainRow, WHITESQUARES, BLACKSQUARES, board);
        }
    }

    cout << "\n\n         (Player - Black Pieces)         \n\n";

    //printing out pieces key
    printKey();
}

void Board::squarePairCreation(char squareColour, int mainRow, int squarePairNum, int subLine, Piece Matrix[8][8])
{
    /**
    *@author Harry Hawkes <hawkes-h@ulster.ac.uk>
    *
    *A function that can be used to print out an indiviual square on the board
    *
    *@param mainRow - holds current row we are on, on the board
    *@param squareColour - a square colour value represented by ASCII char
    *@param squarePairNum - holds current number for square in pair of squares
    *@param subLine - contains value for current line within 1 square
    *@param Matrix[8][8] - an 8x8 matrix array containing layout of the board pieces
    */

    //for loop to go through a single square
    for (int subColumn = 0; subColumn < squareCharSize; subColumn++)
    {
        //If statement determining centre of square
        if (subLine == 1 && subColumn == 3)
        {
            //Nested if/else statement to determine piece on square
            if (Matrix[mainRow][squarePairNum].getType() != '_')
            {
                //Nested if/else to display the piece as lowercase depeneding of piece colour
                if (Matrix[mainRow][squarePairNum].getColour() == 'W')
                {
                    cout << char(tolower(Matrix[mainRow][squarePairNum].getType()));
                }
                else
                {
                    cout << Matrix[mainRow][squarePairNum].getType();
                }
            }
            //else used to only print colour character if no piece on square
            else
            {
                cout << char(squareColour);
            }
        }
        else
        {
            //Else prints out square colour character i.e. white char/black char
            cout << char(squareColour);
        }
    }
}

void Board::printRow(int mainRow, int firstColour, int secondColour, Piece Matrix[8][8])
{
    /**
    *@author Harry Hawkes <hawkes-h@ulster.ac.uk>
    *
    *A function that can be used to print out an indiviual row on the board,
    *corrosponding to an 8x8 matrix array
    *
    *@param mainRow - holds current row we are on, on the board
    *@param firstColour - a square colour value represented by ASCII char
    *@param secondColour - a square colour value represented by ASCII char
    *@param Matrix[8][8] - an 8x8 matrix array containing layout of the board pieces
    */

    //For loop that will iterate through sub characters that make up 1 square.
    for (int subLine = 0; subLine < squareCharSize / 2; subLine++)
    {
        //Nested for loop to split squares into pairs i.e. 4 white, 4 black
        for (int squarePair = 0; squarePair < 4; squarePair++)
        {
            //Creating first square in pair of squares, to make up the row
            squarePairCreation(firstColour, mainRow, squarePair * 2, subLine, Matrix);
            //Creating second square in pair of squares, to make up the row
            squarePairCreation(secondColour, mainRow, squarePair * 2 + 1, subLine, Matrix);

        }
        //If statement to print out row number beside row, in centre of square
        if (1 == subLine)
        {
            cout << "  " << mainRow + 1;
        }
        cout << "\n";
    }
}

void Board::printKey()
{
    /**
    *@author Harry Hawkes <hawkes-h@ulster.ac.uk>
    *
    *A function that can be used to print out the key for pieces displayed on the board
    *
    *@param whiteKey - variable holding a character string containing the key for white pieces
    *@param firstColour - variable holding a character string containing the key for black pieces
    *
    */
    cout << "\n\n--------------------------\n\n";
    cout << "White Pieces = Lowercase\n";
    cout << "Black Pieces = Uppercase\n";
    cout << "\n---------------------------\n";
}
