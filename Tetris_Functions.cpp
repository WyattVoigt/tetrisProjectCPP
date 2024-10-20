#include <iostream>
#include "Tetris_Functions.h"
#include <chrono>
#include <thread>
#include <windows.h>  
using std::cin, std::cout, std::endl;
void makeBoard(char**& table,int rows,int col)
{
    // setting the double pointer to arrays of colloms to use. 
    table = new char*[rows];
    for(int i = 0; i<rows;i++)
    {
        table[i] = new char[col];
    }
    // blank out table
    for(int i = 0;i < rows;i++)
    {
        for(int j = 0; j < col; j++)
        {
            table[i][j] = ' ';
        }
    }
    // make top of border
    for(int i = 0; i < col; i++)
    {
        table[0][i] = '-';
        table[rows-1][i] = '-';
    }
    for(int i = 0; i<rows;i++)
    {
        table[i][0] = '|';
        table[i][col-1] = '|';
    }
    //print table;
    for(int i = 0;i < rows;i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << table[i][j];
        }
        cout << endl;
    }

}
void deleteBoard(char**& table,int rows,int col)
{
    if(table != nullptr)
    {
        for(int i = 0;i<rows;i++)
        {
            if(table[i] != nullptr)
            {
                delete [] table[i];
                table[i] = nullptr;
            }
        }
        delete [] table;
        table = nullptr;
    }
}
int summonPiece(char**& table,int rows, int col)
{
    srand((unsigned) time(NULL));
    int piece = 1;
    if(piece == 1)
    {
        table[2][5] = '*';
        table[2][6] = '*';
        table[2][7] = '*';
        table[2][8] = '*';
        updateBoard(table,rows,col);
    }
    if(piece == 2)
    {
        table[1][6] = '*';
        table[2][6] = '*';
        table[1][7] = '*';
        table[2][7] = '*';
        updateBoard(table,rows,col);
    }
    if(piece == 3)
    {
        table[2][5] = '*';
        table[2][6] = '*';
        table[1][6] = '*';
        table[1][7] = '*';
        updateBoard(table,rows,col);
    }
    if(piece == 4)
    {
        table[1][6] = '*';
        table[1][7] = '*';
        table[2][7] = '*';
        table[2][8] = '*';
        updateBoard(table,rows,col);
    }
    if(piece == 5)
    {
        table[2][5] = '*';
        table[2][6] = '*';
        table[2][7] = '*';
        table[1][7] = '*';
        updateBoard(table,rows,col);
    }
    if(piece == 6)
    {
        table[1][6] = '*';
        table[2][6] = '*';
        table[2][7] = '*';
        table[2][8] = '*';
        updateBoard(table,rows,col);
    }
    if(piece == 7)
    {
        table[1][6] = '*';
        table[2][5] = '*';
        table[2][6] = '*';
        table[2][7] = '*';
        updateBoard(table,rows,col);
    }
    return piece;
}
void updateBoard(char**& table,int rows,int col)
{
    system("cls");
    for(int i = 0;i < rows;i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << table[i][j];
        }
        cout << endl;
    }
}
void moveDownToEnd(char**& table, int pieceNumber,int rows, int col)
{
    if(pieceNumber == 1)
    {
        int position1r = 2;
        int position1c = 5;
        int position2r = 2;
        int position2c = 6;
        int position3r = 2;
        int position3c = 7;
        int position4r = 2;
        int position4c = 8;
        while(table[position1r+1][position1c] != '*' && table[position2r+1][position2c] != '*' && table[position3r+1][position3c] != '*' && table[position4r+1][position4c] != '*' && table[position1r+1][position1c] != '-' && table[position2r+1][position2c] != '-' && table[position3r+1][position3c] != '-' && table[position4r+1][position4c] != '-')
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            table[position1r][position1c] = ' ';
            table[position2r][position2c] = ' ';
            table[position3r][position3c] = ' ';
            table[position4r][position4c] = ' ';
            position1r++;
            position2r++;
            position3r++;
            position4r++;
            table[position1r][position1c] = '*';
            table[position2r][position2c] = '*';
            table[position3r][position3c] = '*';
            table[position4r][position4c] = '*';
            updateBoard(table,rows,col);
            // take input to spin oreintation and move left/right. 
            if(GetAsyncKeyState(VK_RIGHT)&&table[position1r][position1c+1] != '|'&&table[position2r][position2c+1] != '|'&&table[position3r][position3c+1] != '|'&&table[position4r][position4c+1] != '|')// and not on border
            {

                table[position1r][position1c] = ' ';
                table[position2r][position2c] = ' ';
                table[position3r][position3c] = ' ';
                table[position4r][position4c] = ' ';
                position1c++;
                position2c++;
                position3c++;
                position4c++;
                table[position1r][position1c] = '*';
                table[position2r][position2c] = '*';
                table[position3r][position3c] = '*';
                table[position4r][position4c] = '*';
                updateBoard(table,rows,col);
            }
            if(GetAsyncKeyState(VK_LEFT)&&table[position1r][position1c-1] != '|'&&table[position2r][position2c-1] != '|'&&table[position3r][position3c-1] != '|'&&table[position4r][position4c-1] != '|')// and not on border
            {
                table[position1r][position1c] = ' ';
                table[position2r][position2c] = ' ';
                table[position3r][position3c] = ' ';
                table[position4r][position4c] = ' ';
                position1c--;
                position2c--;
                position3c--;
                position4c--;
                table[position1r][position1c] = '*';
                table[position2r][position2c] = '*';
                table[position3r][position3c] = '*';
                table[position4r][position4c] = '*';
                updateBoard(table,rows,col);
            }
        }
    }
}
// copy and paste above for other pieces editing the starting points.
// then implement the game in a while loop to create a new piece once the moveodwnfunction finishes.^aka just create a new piece then mo 
