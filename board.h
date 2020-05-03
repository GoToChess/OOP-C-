#pragma once

/**
*A header file containing board class for board display, and declaration of board layout
*
*@author Harry Hawkes <hawkes-h@ulster.ac.uk>
*@license http://www.gnu.org/copyleft/gpl.html
*@copyright Harry Hawkes 2020
*
*/

#include <iostream>

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
*/

private:
    //Board class variables that can be used privetly

    //ASCII Character for white and black are rectangular, squareCharSize defines a width as to make them
    //Square, 6 Characters wide.
    int squareCharSize = 6;

public:
    //Board class Functions that can be used publicly to display board
    void print_board(Piece matrix[8][8]);
    void printRow(int mainRow, int firstColour, int secondColour, Piece Matrix[8][8]);
    
};

//Use of the 'Pieces' class from Pieces.h to create pieces for the board
//Piece constructor used to set colour and type of piece
Piece piece1('W', 'p'), piece2('W', 'r'), piece3('W', 'n'), piece4('W', 'b'), piece5('W', 'k'), piece6('W', 'q'), piece7('_', '_'), piece8('B', 'P'), piece9('B', 'R'), piece10('B', 'N'), piece11('B', 'B'), piece12('B', 'K'), piece13('B', 'Q');

//Creating an 8x8 matrix array of declared pieces
//Sets inital board setup
Piece matrix[8][8] = {
    {piece1, piece1, piece1, piece1, piece1, piece1, piece1, piece1},
    {piece2, piece3, piece4, piece5, piece6, piece4, piece3, piece2},
    {piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7},
    {piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7},
    {piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7},
    {piece7, piece7, piece7, piece7, piece7, piece7, piece7, piece7},
    {piece9, piece10, piece11, piece12, piece13, piece11, piece10, piece9},
    {piece8, piece8, piece8, piece8, piece8, piece8, piece8, piece8}
};

void Board::print_board(Piece matrix[8][8])
{
    /**
    *@author Harry Hawkes <hawkes-h@ulster.ac.uk>
    *
    *Function to display a visual representation of the board
    *
    *@param matrix[8][8] - an 8x8 matrix array containing layout of the board pieces
    *@return void (nothing)
    */

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
            printRow(mainRow, BLACKSQUARES, WHITESQUARES, matrix);
        }

        else
        {
            ////For row starting with a white squares i.e. 1/3/5/7, runs printLine function to
            //display row, with corrosponding pieces according to 8x8 matrix
            printRow(mainRow, WHITESQUARES, BLACKSQUARES, matrix);
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
    *@param mainRow
    *@param firstColour
    *@param secondColour
    *@param Matrix[8][8] - an 8x8 matrix array containing layout of the board pieces
    */

    //For loop that will iterate through sub characters that make up 1 square.
    for (int subLine = 0; subLine < squareCharSize / 2; subLine++)
    {
        //Nested for loop to split squares into pairs i.e. 4 white, 4 black
        for (int squarePair = 0; squarePair < 4; squarePair++)
        {
            //Nested for loop going throuh first square of pair
            for (int subColumn = 0; subColumn < squareCharSize; subColumn++)
            {
                //If/else statement to determine centre of square
                if (subLine == 1 && subColumn == 3)
                {
                    //Using a ternary operatator to display piece type, in position,
                    //if it isnt a blank piece
                    if (Matrix[mainRow][squarePair * 2 + 1].getType() != '_')
                    {
                        //Nested if/else to display convert white pieces to lower case
                        if (Matrix[mainRow][squarePair * 2].getColour() == 'W')
                        {   
                            //Printing lower case piece type
                            std::cout << char(tolower(Matrix[mainRow][squarePair * 2].getType()));
                        }
                        else
                        {
                            std::cout << Matrix[mainRow][squarePair * 2].getType();
                        }
                    }
                    else
                    {
                        std::cout << char(firstColour);
                    }
                }
                //Else prints out square colour character i.e. white char/black char
                else
                {
                    cout << char(firstColour);
                }
            }

            //Nested for loop going throuh second square of pair
            for (int subColumn = 0; subColumn < squareCharSize; subColumn++)
            {
                //If/else statement to determine centre of square
                if (subLine == 1 && subColumn == 3)
                {
                    //Nested if/else to display piece type, in position,
                    //if it isnt a blank piece
                    if (Matrix[mainRow][squarePair * 2 + 1].getType() != '_')
                    {
                        //Nested if/else to display convert white pieces to lower case
                        if (Matrix[mainRow][squarePair * 2 + 1].getColour() == 'W')
                        {
                            //Printing lower case piece type
                            std::cout << char(tolower(Matrix[mainRow][squarePair * 2 + 1].getType()));
                        }
                        else
                        {
                            std::cout << Matrix[mainRow][squarePair * 2 + 1].getType();
                        }
                    }
                    else
                    {
                        std::cout << char(secondColour);
                    }
                }
                //Else prints out square colour character i.e. white char/black char
                else
                {
                    cout << char(secondColour);
                }
            }
        }
        //If statement to print out row number beside row, in centre of square
        if (1 == subLine)
        {
            cout << "  " << mainRow + 1;
        }
        cout << "\n";
    }
}
