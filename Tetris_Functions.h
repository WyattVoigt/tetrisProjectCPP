#ifndef TETRIS
#define TETRIS

void makeBoard(char**& table,int rows, int col);
void deleteBoard(char**& table,int rows, int col);

//spawn in piece from 5 options. 
int summonPiece(char**& table,int rows, int col);
//updateBoard;
void updateBoard(char**& table,int rows,int col); //prints the board
//check for tetris when nothing moving.
void moveDownToEnd(char**& table,int pieceNumber, int rows, int col);
//spawn in peice after nothing moving/game doesnt end.

// if check condition then gameover.
void gameOver();















#endif