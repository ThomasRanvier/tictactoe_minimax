#include "TicTacToe.h"

const int P1 = 1;
const int P2 = 2;
const char GLYPHS[3][3][3] = {
        {
                {' ', ' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}
        },
        {
                {'#', ' ', '#'},
                {' ', '#', ' '},
                {'#', ' ', '#'}
        },
        {
                {'#', '#', '#'},
                {'#', ' ', '#'},
                {'#', '#', '#'}
        },
};

TicTacToe::TicTacToe() {
    for (int x(0); x < 3; x++) {
        for (int y(0); y < 3; y++) {
            grid[x][y] = 0;
        }
    }
    displayGrid();
}

void TicTacToe::displayWinner() {
    if (isWinner(P1)) {
        std::cout << "\n\nP1 player wins !" << std::endl;
    } else if (isWinner(P2)) {
        std::cout << "\n\nP2 wins !" << std::endl;
    } else {
        std::cout << "\n\nNo one wins !" << std::endl;
    }
}

bool TicTacToe::endOfGame() {
    bool gridIsFull = true;
    for (int x(0); x < 3; x++) {
        for (int y(0); y < 3; y++) {
            if (grid[x][y] == 0) {
                gridIsFull = false;
            }
        }
    }
    return isWinner(P1) || isWinner(P2) || gridIsFull;
}

void TicTacToe::setValue(int x, int y, int value) {
    grid[x][y] = value;
}

void TicTacToe::displayGrid() {
    std::cout << "\n";
    displayGridHeader();
    for (int i(0); i < 3; i++) {
        int line[3] = {grid[0][i], grid[1][i], grid[2][i]};
        displayGridLine(line, i + 1);
        if (i < 2) {
            displayGridLineSeparator();
        }
    }
    std::cout << "\n";
}

void TicTacToe::displayGridLine(int line[3], int lineIndex) {
    for (int lineLine(0); lineLine < 3; lineLine++) {
        if (lineLine == 1) {
            std::cout << lineIndex;
        } else {
            std::cout << ' ';
        }
        std::cout << '|';

        for (int index(0); index < 3; index++) {
            for (int column(0); column < 3; column++) {
                std::cout << GLYPHS[line[index]][lineLine][column];
            }
            std::cout << (index < 2 ? "|" : "|\n");
        }
    }
}

void TicTacToe::displayGridLineSeparator() {
    for (int i(0); i < 14; i++) {
        std::cout << '-';
    }
    std::cout << '\n';
}

void TicTacToe::displayGridHeader() {
    std::cout << " | 1 | 2 | 3 |\n";
    displayGridLineSeparator();
}

bool TicTacToe::isWinner(int p) {
    return ((grid[0][0] == p && grid[0][1] == p && grid[0][2] == p) ||
            (grid[1][0] == p && grid[1][1] == p && grid[1][2] == p) ||
            (grid[2][0] == p && grid[2][1] == p && grid[2][2] == p) ||
            (grid[0][0] == p && grid[1][1] == p && grid[2][2] == p) ||
            (grid[0][2] == p && grid[1][1] == p && grid[2][0] == p) ||
            (grid[0][0] == p && grid[1][0] == p && grid[2][0] == p) ||
            (grid[0][1] == p && grid[1][1] == p && grid[2][1] == p) ||
            (grid[0][2] == p && grid[1][2] == p && grid[2][2] == p));
}

void TicTacToe::getGrid(int cpGrid[3][3]) {
    for (int x(0); x < 3; x++) {
        for (int y(0); y < 3; y++) {
            cpGrid[x][y] = grid[x][y];
        }
    }
}
