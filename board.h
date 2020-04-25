#include <iostream>
using namespace std;

class chessBoard
{
    
private:
    //Creating a character array, for inital board layout i.e. a visual representation for the console
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
    
    
    
public:
    //Class Functions
    void movePiece(Piece Array[8][8], int firstCol, int firstRow, int lastCol, int lastRow); //To move a piece around the board
    void updateDispBoard(int firstCol, int firstRow, int lastCol, int lastRow); //Updating visual board
    void boardDisplay(); //Displaying the board at the present time
    
    
};




void chessBoard::movePiece(Piece Array[8][8], int firstCol, int firstRow, int lastCol, int lastRow)
{
    //A function to Move Pieces
    //Takes inputs: an array of pieces, as well as complete move coordinates
    
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
    //std::cout << "Real Board After Move...\n";
    //for(int i = 0; i<8; i++){
    //for(int j = 0; j<8; j++){
    //std::cout<< Array[i][j].getType() << " ";;
    //}
    
    //std::cout << "\n";
    //}
    
}

void chessBoard::updateDispBoard(int firstCol, int firstRow, int lastCol, int lastRow)
{
    //A member function, in order to update visual board
    //Takes inputs of all move coordinates
    
    //Conversion of real Co-ordinates mapped to Display Board
    //An array to store move coordinates
    int coordArray[4] = {firstCol, firstRow, lastCol, lastRow};
    
    //Display board equivelent coordinates, to that of real board.
    //dispArrayCoord[0] = rows of display board, dispArrayCoord[1] = columns of display board
    int dispArrayCoord[2][8] =
    {
        {3, 7, 11, 15, 19, 23, 27, 31},
        {5, 9, 13, 17, 21, 25, 29, 31}
    };
    
    //Getting inital row/column value
    int initRow = dispArrayCoord[0][coordArray[1]];
    //std::cout << "Inital Row ..."<< initRow << " \n";
    int initCol = dispArrayCoord[1][coordArray[0]];
    //std::cout << "Inital Column ..."<< initCol << " \n";
    
    //Getting final row/column value
    int finalRow = dispArrayCoord[0][coordArray[3]];
    //std::cout << "Final Row ..."<< finalRow << " \n";
    int finalCol = dispArrayCoord[1][coordArray[2]];
    //std::cout << "Final Column ..."<< finalCol << " \n";
    
    //Displaying char in the char array dispBoard... not working
    char initChar = dispBoard[initRow][initCol];
    //std::cout << "Inital Char ..."<< dispBoard[initRow][initCol] << " \n";
    
    
    char lastChar = dispBoard[finalRow][finalCol];
    //std::cout << "Final Char ..." << lastChar << " \n";
    
    //Setting the char at inital and final positions equal to each other for the change
    dispBoard[initRow][initCol] = lastChar;
    dispBoard[finalRow][finalCol] = initChar;
    
}

void chessBoard::boardDisplay()
{
    //A function to display the visual board at present
    
    //For loop to iterate through each character in the board array.
    for(int i = 0; i<34; i++){
        for(int j = 0; j<36; j++){
            std::cout<< dispBoard[i][j]<< " ";;
        }
        
        std::cout << "\n";
    }
}
