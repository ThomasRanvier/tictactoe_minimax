#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <vector>

class TicTacToe {
private:
    int grid[3][3];

    void displayGridLine(int [3], int);
    void displayGridLineSeparator();
    void displayGridHeader();

public:
    TicTacToe();

    bool isWinner(int);
    void setValue(int, int, int);
    bool endOfGame();
    void getGrid(int [3][3]);
    void displayWinner();
    void displayGrid();
};

#endif