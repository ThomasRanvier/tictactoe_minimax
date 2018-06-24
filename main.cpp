#include "TicTacToe.h"

struct Move {
    int x, y, score;
};

void playerPlays(TicTacToe *, const int i);
void botPlays(TicTacToe *, int);
std::vector<Move> allAvailableMoves(int [3][3]);
Move minimax(TicTacToe *, int, int);

const int P1 = 1;
const int P2 = 2;

int main() {
    std::srand(std::time(NULL));
    bool order = std::rand() & 1;
    int mode;

    TicTacToe ticTacToe = TicTacToe();

    std::cout << "PVP (1), player vs AI (2), AI vs AI (3) ?" << std::endl;
    std::cin >> mode;

    while (!ticTacToe.endOfGame()) {
        if (mode == 1) {
            playerPlays(&ticTacToe, P1);
            if (!ticTacToe.endOfGame()) {
                playerPlays(&ticTacToe, P2);
            }
        } else if (mode == 2){
            if (order) {
                botPlays(&ticTacToe, P1);
                if (!ticTacToe.endOfGame()) {
                    playerPlays(&ticTacToe, P2);
                }
            } else {
                playerPlays(&ticTacToe, P1);
                if (!ticTacToe.endOfGame()) {
                    botPlays(&ticTacToe, P2);
                }
            }
        } else {
            botPlays(&ticTacToe, P1);
            if (!ticTacToe.endOfGame()) {
                botPlays(&ticTacToe, P2);
            }
        }
    }

    ticTacToe.displayWinner();
}

void playerPlays(TicTacToe * ticTacToe, const int p) {
    Move move;
    int grid[3][3];
    ticTacToe->getGrid(grid);

    do {
        std::cout << "P" << p << " plays" << std::endl;
        std::cout << "Enter x : " << std::endl;
        std::cin >> move.x;
        move.x--;
        std::cout << "Enter y : " << std::endl;
        std::cin >> move.y;
        move.y--;
    } while (grid[move.x][move.y] != 0);
    ticTacToe->setValue(move.x, move.y, p);

    ticTacToe->displayGrid();
}

void botPlays(TicTacToe * ticTacToe, int p) {
    std::cout << "Bot is playing P" << p << std::endl;
    int grid[3][3];
    ticTacToe->getGrid(grid);
    Move result = minimax(ticTacToe, p, p);
    ticTacToe->setValue(result.x, result.y, p);

    ticTacToe->displayGrid();
}

Move minimax(TicTacToe * ticTacToe, int p, int initP) {
    Move result;

    if (ticTacToe->endOfGame()) {
        if (ticTacToe->isWinner(P1)) {
            if (P1 == initP) {
                result.score = 10;
            } else {
                result.score = -10;
            }
        } else if (ticTacToe->isWinner(P2)) {
            if (P2 == initP) {
                result.score = 10;
            } else {
                result.score = -10;
            }
        } else {
            result.score = 0;
        }
        return result;
    }

    int grid[3][3];
    ticTacToe->getGrid(grid);
    std::vector<Move> moves = allAvailableMoves(grid);

    for (int i(0); i < moves.size(); i++) {
        ticTacToe->setValue(moves[i].x, moves[i].y, p);

        moves[i].score = minimax(ticTacToe, (p == 1 ? 2 : 1), initP).score;

        ticTacToe->setValue(moves[i].x, moves[i].y, 0);
    }

    int bestMoveIndex = 0;
    if (p == initP) {
        //Maximize
        int bestScore = -1000000;
        for (int i(0); i < moves.size(); i++) {
            if (moves[i].score > bestScore) {
                bestScore = moves[i].score;
                bestMoveIndex = i;
            }
        }
    } else {
        //Minimize
        int bestScore = 1000000;
        for (int i(0); i < moves.size(); i++) {
            if (moves[i].score < bestScore) {
                bestScore = moves[i].score;
                bestMoveIndex = i;
            }
        }
    }

    return moves[bestMoveIndex];
}

std::vector<Move> allAvailableMoves(int grid[3][3]) {
    std::vector<Move> moves;
    for (int x(0); x < 3; x++) {
        for (int y(0); y < 3; y++) {
            if (grid[x][y] == 0) {
                Move move;
                move.x = x;
                move.y = y;
                move.score = 0;
                moves.push_back(move);
            }
        }
    }
    return moves;
}
