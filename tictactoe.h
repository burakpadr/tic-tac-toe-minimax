#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <algorithm>

using namespace std;

class TicTacToe {
    private:
        static const char symbols[2];
        enum ReturnFlag {MAX, MIN}; // This enum was declared to assist the minimax algorithm

        char playerSymbol;
        char computerSymbol;
        char moves[9];
        int totalMovement;
        int turn;
        int winner;

        int minimax(int height); // This function is the implementation of the minimax algorithm.

    public:
        enum Role {ROLE_PLAYER, ROLE_COMPUTER};
        enum Winner {WINNER_PLAYER=-1, WINNER_SCORLESS=0, WINNER_COMPUTER=1};

        TicTacToe();
        char getPlayerSymbol() const;
        char getComputerSymbol() const;
        int getTurn() const;
        int getTotalMovement() const;
        void renderTheView() const;
        bool gameIsEnded();
        int whoIsWinner() const;
        void move();
};
#endif