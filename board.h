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
    
    friend class chessBoard;
};

Piece::Piece(char constructorcolour, char constructortype)
{
    //calls input function, colour first parameter, type of piece second parameter
    input(constructorcolour, constructortype);
}

void Piece::input(char newcolour, char newtype)
{
    
    //TODO: ADD SO YOU CAN ENTER A CAPITAL OR LOWER CASE LETTER AND IT CONVERTS TO UPPERCASE
    if (newcolour == 'W' || newcolour == 'B' || newcolour == 'X') Colour = newcolour; //colour can be white black or none
    else std::cout << "ERROR: you have attempted to create a piece with a colour that is not valid, valid colours, are B, W , and  _" << std::endl;
    //else should make you restart if you make the object with an invalid colour
    if (newtype == 'P' || newtype == 'K' || newtype == 'Q' || newtype == 'R' || newtype == 'B' || newtype == 'N'|| newtype == 'k' || newtype == 'q' || newtype == 'r' || newtype == 'b' || newtype == 'n' || newtype == 'X') Type = newtype;
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

class chessBoard
{
    //Creating a character array, for inital board layout
    char dispBoard[34][36] =
    {
        {' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', 'B', ' ', ' ', ' ', 'C', ' ', ' ', ' ', 'D', ' ', ' ', ' ', 'E', ' ', ' ', ' ', 'F', ' ', ' ', ' ', 'G', ' ', ' ', ' ', 'H', ' ', ' '},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '1', ' ', '#', ' ', 'R', ' ', '#', ' ', 'N', ' ', '#', ' ', 'B', ' ', '#', ' ', 'K', ' ', '#', ' ', 'Q', ' ', '#', ' ', 'B', ' ', '#', ' ', 'N', ' ', '#', ' ', 'R', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '2', ' ', '#', ' ', 'P', ' ', '#', ' ', 'P', ' ', '#', ' ', 'P', ' ', '#', ' ', 'P', ' ', '#', ' ', 'P', ' ', '#', ' ', 'P', ' ', '#', ' ', 'P', ' ', '#', ' ', 'P', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '3', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '4', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '5', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '6', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '7', ' ', '#', ' ', 'p', ' ', '#', ' ', 'p', ' ', '#', ' ', 'p', ' ', '#', ' ', 'p', ' ', '#', ' ', 'p', ' ', '#', ' ', 'p', ' ', '#', ' ', 'p', ' ', '#', ' ', 'p', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '8', ' ', '#', ' ', 'r', ' ', '#', ' ', 'n', ' ', '#', ' ', 'b', ' ', '#', ' ', 'k', ' ', '#', ' ', 'q', ' ', '#', ' ', 'b', ' ', '#', ' ', 'r', ' ', '#', ' ', 'n', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        
    };
    
    //White Pieces
    //Piece wPawn1('W', 'P'), wPawn2('W', 'P'), wPawn3('W', 'P'), wPawn4('W', 'P'), wPawn5('W', 'P'), wPawn6('W', 'P'), wPawn7('W', 'P'), wPawn8('W', 'P');
    //Piece wRook1('W', 'R'), wRook2('W', 'R');
    //Piece wKnight1('W', 'N'), wKnight2('W', 'N');
    //Piece wBishop1('W', 'B'), wBishop2('W', 'B');
    //Piece wKing('W', 'K'), wQueen('W', 'Q');
    
    //Black Pieces
    //Piece bPawn1('B', 'P'), bPawn2('B', 'P'), bPawn3('B', 'P'), bPawn4('B', 'P'), bPawn5('B', 'P'), bPawn6('B', 'P'), bPawn7('B', 'P'), bPawn8('B', 'P');
    //Piece bRook1('B', 'R'), bRook2('B', 'R');
    //Piece bKnight1('B', 'N'), bKnight2('B', 'N');
    //Piece bBishop1('B', 'B'), bBishop2('B', 'B');
    //Piece bKing('B', 'K'), bQueen('B', 'Q');
    
    //Blank Pieces
    //Piece blank1('X', 'X'), blank2('X', 'X'), blank3('X', 'X'), blank4('X', 'X'), blank5('X', 'X'), blank6('X', 'X'), blank7('X', 'X'), blank8('X', 'X');
    //Piece blank9('X', 'X'), blank10('X', 'X'), blank11('X', 'X'), blank12('X', 'X'), blank13('X', 'X'), blank14('X', 'X'), blank15('X', 'X'), blank16('X', 'X');
    //Piece blank17('X', 'X'), blank18('X', 'X'), blank19('X', 'X'), blank20('X', 'X'), blank21('X', 'X'), blank22('X', 'X'), blank23('X', 'X'), blank24('X', 'X');
    //Piece blank25('X', 'X'), blank26('X', 'X'), blank27('X', 'X'), blank28('X', 'X'), blank29('X', 'X'), blank30('X', 'X'), blank31('X', 'X'), blank32('X', 'X');
    
    //White Pieces
    //Piece wPawn1{'W', 'P'}, wPawn2{'W', 'P'}, wPawn3{'W', 'P'}, wPawn4{'W', 'P'}, wPawn5{'W', 'P'}, wPawn6{'W', 'P'}, wPawn7{'W', 'P'}, wPawn8{'W', 'P'};
    //Piece wRook1{'W', 'R'}, wRook2{'W', 'R'};
    //Piece wKnight1{'W', 'N'}, wKnight2{'W', 'N'};
    //Piece wBishop1{'W', 'B'}, wBishop2{'W', 'B'};
    //Piece wKing{'W', 'K'}, wQueen{'W', 'Q'};
    
    //Black Pieces
    //Piece bPawn1{'B', 'P'}, bPawn2{'B', 'P'}, bPawn3{'B', 'P'}, bPawn4{'B', 'P'}, bPawn5{'B', 'P'}, bPawn6{'B', 'P'}, bPawn7{'B', 'P'}, bPawn8{'B', 'P'};
    //Piece bRook1{'B', 'R'}, bRook2{'B', 'R'};
    //Piece bKnight1{'B', 'N'}, bKnight2{'B', 'N'};
    //Piece bBishop1{'B', 'B'}, bBishop2{'B', 'B'};
    //Piece bKing{'B', 'K'}, bQueen{'B', 'Q'};
    
    //Blank Pieces
    //Piece blank1{'X', 'X'}, blank2{'X', 'X'}, blank3{'X', 'X'}, blank4{'X', 'X'}, blank5{'X', 'X'}, blank6{'X', 'X'}, blank7{'X', 'X'}, blank8{'X', 'X'};
    //Piece blank9{'X', 'X'}, blank10{'X', 'X'}, blank11{'X', 'X'}, blank12{'X', 'X'}, blank13{'X', 'X'}, blank14{'X', 'X'}, blank15{'X', 'X'}, blank16{'X', 'X'};
    //Piece blank17{'X', 'X'}, blank18{'X', 'X'}, blank19{'X', 'X'}, blank20{'X', 'X'}, blank21{'X', 'X'}, blank22{'X', 'X'}, blank23{'X', 'X'}, blank24{'X', 'X'};
    //Piece blank25{'X', 'X'}, blank26{'X', 'X'}, blank27{'X', 'X'}, blank28{'X', 'X'}, blank29{'X', 'X'}, blank30{'X', 'X'}, blank31{'X', 'X'}, blank32{'X', 'X'};
    
    

    
public:
    //Class Functions to date
    chessBoard(); //constructor
    void movePiece(Piece Array[8][8], int firstCol, int firstRow, int lastCol, int lastRow); //To move a piece around the board
    void updateBoard(int firstCol, int firstRow, int lastCol, int lastRow); //updating board
    void initalBoardDisplay(); //displaying the board at the present time
    
    
    
};



chessBoard::chessBoard()
{
}

void chessBoard::movePiece(Piece Array[8][8], int firstCol, int firstRow, int lastCol, int lastRow)
{
    //Take inputs: an array of pieces, as well as complete move coordinates
    //Converts object types in order to move pieces
    
    //Initialisation arrays for move coordinates can be stored
    int initLoc[2] = {0, 0};
    int moveToLoc[2] = {0, 0};
    
    //Setting elements indexs for two arrays to represent rows and columns
    initLoc[0] = firstRow;
    initLoc[1] = firstCol;
    
    moveToLoc[0] = lastRow;
    moveToLoc[1] = lastCol;
    
    
    //Inital realBoard array
    //std::cout<< "Printing realBoard array...\n";
    //for(int i = 0; i<8; i++){
        //for(int j = 0; j<8; j++){
            //std::cout<< Array[i][j].getType() << " ";;
        //}
        
        //std::cout << "\n";
    //}
    
    std::cout << "\n";
    
    //Storing inital Piece Type, and last Piece Type
    char initType = Array[initLoc[0]][initLoc[1]].getType();
    char moveToType = Array[moveToLoc[0]][moveToLoc[1]].getType();
    
    //Switching piece types to make move occur
    Array[initLoc[0]][initLoc[1]].Type = moveToType;
    Array[moveToLoc[0]][moveToLoc[1]].Type = initType;
    
    std::cout << "\n";
    
    //Printing realBoard after move
    std::cout << "Board After Move...\n";
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            std::cout<< Array[i][j].getType() << " ";;
        }
        
        std::cout << "\n";
    }
    
}

void chessBoard::updateBoard(int firstCol, int firstRow, int lastCol, int lastRow)
{
    //Conversion of real Co-ordinates mapped to Display Board
    int coordArray[4] = {firstCol, firstRow, lastCol, lastRow};
    
    //Display board equivelent coordinates
    int dispArrayCoord[2][8] =
    {
        {6, 10, 14, 18, 22, 26, 30, 34},
        {4, 8, 12, 16, 20, 24, 28, 32}
    };
    
    //Getting inital row/column value
    int initRow = dispArrayCoord[1][coordArray[1]];
    int initCol = dispArrayCoord[0][coordArray[0]];
    
    //Getting final row/column value
    int finalRow = dispArrayCoord[1][coordArray[3]];
    int finalCol = dispArrayCoord[0][coordArray[2]];
    
    //Displaying char in the char array dispBoard... not working
    char initChar = dispBoard[initRow][initCol];
    std::cout << "Inital Char ..."<< dispBoard[initRow][initCol] << " \n";
    

    char lastChar = dispBoard[finalRow][finalCol];
    std::cout << "Inital Char ..." << initChar << " \n";
    
    //Setting the char at inital and final positions equal to each other for the change
    dispBoard[initRow][initCol] = lastChar;
    dispBoard[finalRow][finalCol] = initChar;
    
}

void chessBoard::initalBoardDisplay()
{
    
    //Prints out dispBoard char array to display board to user
    
    for(int i = 0; i<34; i++){
        for(int j = 0; j<36; j++){
            std::cout<< dispBoard[i][j]<< " ";;
        }
        
        std::cout << "\n";
    }
}

int main() {
    
    //White Pieces
    Piece wPawn1('W', 'P'), wPawn2('W', 'P'), wPawn3('W', 'P'), wPawn4('W', 'P'), wPawn5('W', 'P'), wPawn6('W', 'P'), wPawn7('W', 'P'), wPawn8('W', 'P');
    Piece wRook1('W', 'R'), wRook2('W', 'R');
    Piece wKnight1('W', 'N'), wKnight2('W', 'N');
    Piece wBishop1('W', 'B'), wBishop2('W', 'B');
    Piece wKing('W', 'K'), wQueen('W', 'Q');
    
    //Black Pieces
    Piece bPawn1('B', 'P'), bPawn2('B', 'P'), bPawn3('B', 'P'), bPawn4('B', 'P'), bPawn5('B', 'P'), bPawn6('B', 'P'), bPawn7('B', 'P'), bPawn8('B', 'P');
    Piece bRook1('B', 'R'), bRook2('B', 'R');
    Piece bKnight1('B', 'N'), bKnight2('B', 'N');
    Piece bBishop1('B', 'B'), bBishop2('B', 'B');
    Piece bKing('B', 'K'), bQueen('B', 'Q');
    
    //Blank Pieces
    Piece blank1('X', 'X'), blank2('X', 'X'), blank3('X', 'X'), blank4('X', 'X'), blank5('X', 'X'), blank6('X', 'X'), blank7('X', 'X'), blank8('X', 'X');
    Piece blank9('X', 'X'), blank10('X', 'X'), blank11('X', 'X'), blank12('X', 'X'), blank13('X', 'X'), blank14('X', 'X'), blank15('X', 'X'), blank16('X', 'X');
    Piece blank17('X', 'X'), blank18('X', 'X'), blank19('X', 'X'), blank20('X', 'X'), blank21('X', 'X'), blank22('X', 'X'), blank23('X', 'X'), blank24('X', 'X');
    Piece blank25('X', 'X'), blank26('X', 'X'), blank27('X', 'X'), blank28('X', 'X'), blank29('X', 'X'), blank30('X', 'X'), blank31('X', 'X'), blank32('X', 'X');
    
    Piece boardArray[8][8] = {
        {wRook1, wKnight1,wBishop1, wKing, wQueen, wBishop2, wKnight2, wRook2},
        {wPawn1, wPawn2, wPawn3, wPawn4, wPawn5, wPawn6, wPawn7, wPawn8},
        {blank1, blank2, blank3, blank4, blank5, blank6, blank7, blank8},
        {blank1, blank2, blank3, blank4, blank5, blank6, blank7, blank8},
        {blank1, blank2, blank3, blank4, blank5, blank6, blank7, blank8},
        {blank1, blank2, blank3, blank4, blank5, blank6, blank7, blank8},
        {bPawn1, bPawn2, bPawn3, bPawn4, bPawn5, bPawn6, bPawn7, bPawn8},
        {bRook1, bKnight1, bBishop1, bKing, bQueen, bBishop2, bKnight2, bRook2}
    };
    
    chessBoard board;
    
    std::cout << "Initalising... \n";
    board.initalBoardDisplay();
    
    std::cout << "Move Piece... \n";
    board.movePiece(boardArray, 1, 0, 2, 1);
    
    std::cout << "update Board ...\n";
    board.updateBoard(1, 0, 2, 1);
    
    std::cout << "Display Board again...\n";
    board.initalBoardDisplay();
    
    
    
}
