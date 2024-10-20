#include <iostream>
#include "Tetris_Functions.h"
#include <chrono>
#include <thread>
using std::cin, std::cout, std::endl;
int main()
{
    unsigned const int rows = 21;
    unsigned const int col = 12;
    char** table = nullptr;
    makeBoard(table,rows,col);
    while(true)
    {
        int pieceNumber = summonPiece(table,rows,col);
        moveDownToEnd(table,pieceNumber,rows,col);
    }
    int score = 0;

    deleteBoard(table,rows,col);
}