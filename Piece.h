#pragma once

/**
*Class for representing individual pieces in the game of chess
*
*@author Ruairi Caldwell <caldwell-r2@ulster.ac.uk>
*@license http://www.gnu.org/copyleft/gpl.html
*@copyright Ruairi Caldwell 2020
*
*/

#include <iostream>

class Piece
{
	char Colour; //'W' or 'B' or use '_'for objects which will fill up empty squares
	char Type;//P=pawn, K=king, Q=queen, R=rook, B=bishop N=knight, use _ for empty ones which will fill up empty squares
			  //int movecount = 0; //to track if a piece has moved to check if castling is legal

public:
	//TODO: ADD SO YOU CAN ENTER A CAPITAL OR LOWER CASE LETTER AND IT CONVERTS TO UPPERCASE
	//possibly hold original 'File' of piece for en passant

	Piece();
	Piece(char constructorcolour, char constructortype); //constructor with parameters
	void input(char newcolour, char newtype);
	void output(); 
	char getColour();
	char getType();
};

/**
*@author Ruairi Caldwell
*
*constructor to set the colour and type of piece by calling the input function
*
*@param constructorcolour the colour of the piece to be created
*@param constructortype the type of piece to be created
*@see Piece::input
*/
Piece::Piece(char constructorcolour, char constructortype)
{
	//calls input function, colour first parameter, type of piece second parameter
	input(constructorcolour, constructortype);
}

/**
*@author Ruairi Caldwell
*
*overloaded constructor used if no constructor is called, creates a "blank" piece by setting the both colour and type = '_'
*
*/
Piece::Piece()
{
	Colour = '_';
	Type = '_';
}


/**
*@author Ruairi Caldwell
*
*sets the variables for colour and type of piece
*
*@param newcolour the colour of the piece to be created, 'W'=white, 'B'=black, '_' used for empty squares
*@param newtype the type of piece to be created, 'P'=pawn, 'K'=king, 'Q'=queen, 'R'=rook, 'B'=bishop 'N'=knight, use '_' for empty squares
*/
void Piece::input(char newcolour, char newtype)
{
	//TODO: ADD SO YOU CAN ENTER A CAPITAL OR LOWER CASE LETTER AND IT CONVERTS TO UPPERCASE
	if (newcolour == 'W' || newcolour == 'B' || newcolour == '_') Colour = newcolour; //sets colour of piece
	//error if invalid selection
	else std::cout << "ERROR: you have attempted to create a piece with a colour that is not valid, valid colours, are B, W , and  _" << std::endl;

	if (newtype == 'P' || newtype == 'K' || newtype == 'Q' || newtype == 'R' || newtype == 'B' || newtype == 'N' || newtype == '_') Type = newtype;
	else std::cout << "ERROR: you have attempted to create a piece with an invalid type, valid types are P, K, Q, R, B, N and _" << std::endl;
	//same as above could add error correction here for if an invalid letter is typed in

}

//possibly remove this if not needed
void Piece::output()
{
	std::cout << "This is a " << Colour << " piece which is of type " << Type << std::endl;
}

/**
*@author Ruairi Caldwell
*
*returns the colour of the piece
*
*@return returns character which represents the colour of the piece
*/
char Piece::getColour()
{
	return Colour;
}

/**
*@author Ruairi Caldwell
*
*returns the type of the piece
*
*@return returns character which represents the type of the piece
*/
char Piece::getType()
{
	return Type;
}
