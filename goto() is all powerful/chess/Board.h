#pragma once

#include "pieces.h"

#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF

class Board
{
private:

public:
    void print_board(Piece matrix[8][8]);
    void printLine(int iLine, int iColor1, int iColor2, Piece Matrix[8][8]);
};

Piece piece1('W', 'r'), piece2('W', 'n'), piece3('W', 'b'), piece4('W', 'q'), piece5('W', 'k'), piece6('W', 'p');
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


void Board::print_board(Piece matrix[8][8])
{
    std::cout << "   A     B     C     D     E     F     G     H\n\n";

    for (int iLine = 7; iLine >= 0; iLine--)
    {
        if (iLine % 2 == 0)
        {
            // Line starting with BLACK
            printLine(iLine, BLACK_SQUARE, WHITE_SQUARE, matrix);
        }

        else
        {
            // Line starting with WHITE
            printLine(iLine, WHITE_SQUARE, BLACK_SQUARE, matrix);
        }
    }
}

void Board::printLine(int iLine, int iColor1, int iColor2, Piece Matrix[8][8])
{
    //whiteToLowCase(Matrix);

    // Define the CELL variable here.
    // It represents how many horizontal characters will form one squarite
    // The number of vertical characters will be CELL/2
    // You can change it to alter the size of the board
    // (an odd number will make the squares look rectangular)
    int CELL = 6;

    // Since the width of the characters BLACK and WHITE is half of the height,
    // we need to use two characters in a row.
    // So if we have CELL characters, we must have CELL/2 sublines
    for (int subLine = 0; subLine < CELL / 2; subLine++)
    {
        // A sub-line is consisted of 8 cells, but we can group it
        // in 4 iPairs of black&white
        for (int iPair = 0; iPair < 4; iPair++)
        {
            // First cell of the pair
            for (int subColumn = 0; subColumn < CELL; subColumn++)
            {
                // The piece should be in the "middle" of the cell
                // For 3 sub-lines, in sub-line 1
                // For 6 sub-columns, sub-column 3
                if (subLine == 1 && subColumn == 3)
                {
                    //if (Matrix[iLine][iPair * 2].getType != '_')
                    //{
                        //std::cout << Matrix[iLine][iPair * 2].getType;
                    //}
                    //else
                    //{
                        //std::cout << iColor1;
                    //}

                    std::cout << char(Matrix[iLine][iPair * 2].getType() != '_' ?
                        Matrix[iLine][iPair * 2].getType() : iColor1);
                }
                else
                {
                    std::cout << char(iColor1);
                }
            }

            // Second cell of the pair
            for (int subColumn = 0; subColumn < CELL; subColumn++)
            {
                // The piece should be in the "middle" of the cell
                // For 3 sub-lines, in sub-line 1
                // For 6 sub-columns, sub-column 3
                if (subLine == 1 && subColumn == 3)
                {
                    //if (Matrix[iLine][iPair* 2 + 1].getType != '_')
                    //{
                        //std::cout << Matrix[iLine][iPair * 2 + 1].getType;
                    //}
                    //else
                    //{
                        //std::cout << iColor2;
                    //}

                    std::cout << char(Matrix[iLine][iPair * 2 + 1].getType() != '_' ?
                        Matrix[iLine][iPair * 2 + 1].getType() : iColor2);
                }
                else
                {
                    std::cout << char(iColor2);
                }
            }
        }

        if (1 == subLine)
        {
            std::cout << "  " << iLine;
        }

        std::cout << "\n";
    }
}
