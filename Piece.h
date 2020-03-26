#pragma once
#include <iostream>

class Piece
{
	char Colour; //W or B or use X for objects which will fill up empty squares
	char Type;//P=pawn, K=king, Q=queen, R=rook, B=bishop N=knight, use X for empty ones which will fill up empty squares
			  //int movecount = 0; //to track if a piece has moved to check if castling is legal

public:
	//TODO: ADD SO YOU CAN ENTER A CAPITAL OR LOWER CASE LETTER AND IT CONVERTS TO UPPERCASE
	//possibly hold original 'File' of piece for en passant

	Piece(char constructorcolour, char constructortype);
	void input(char newcolour, char newtype);
	void output(); //prints some info about object
				   //void mademove(); possiblye TODO could add a function to register if a piece has made a move useful for checking if 'castling' is legal

				   //find out information about a piece so, for example the board class can look it up before it destroys the object and makes another one on a new square
				   //when a player is making a move. 
	char getColour();
	char getType();
	//void getData(); possibly return a structure or std::pair or something fancy which would return both colour and type instead of get colour, get type although
	//you might not always want to return both of these 
};

Piece::Piece(char constructorcolour, char constructortype)
{
	//calls input function, colour first parameter, type of piece second parameter
	input(constructorcolour, constructortype);
}

void Piece::input(char newcolour, char newtype)
{

	//TODO: ADD SO YOU CAN ENTER A CAPITAL OR LOWER CASE LETTER AND IT CONVERTS TO UPPERCASE
	if (newcolour == 'W' || newcolour == 'B' || newcolour == '_') Colour = newcolour; //colour can be white black or none
	else std::cout << "ERROR: you have attempted to create a piece with a colour that is not valid, valid colours, are B, W , and  _" << std::endl;
	//else should make you restart if you make the object with an invalid colour
	if (newtype == 'P' || newtype == 'K' || newtype == 'Q' || newtype == 'R' || newtype == 'B' || newtype == 'N' || newtype == '_') Type = newtype;
	else std::cout << "ERROR: you have attempted to create a piece with an invalid type, valid types are P, K, Q, R, B, N and _" << std::endl;
	//same as above could add error correction here for if an invalid letter is typed in

}

void Piece::output()
{
	std::cout << "This is a " << Colour << " piece which is of type " << Type << std::endl;
}

char Piece::getColour()
{
	return Colour;
}

char Piece::getType()
{
	return Type;
}
