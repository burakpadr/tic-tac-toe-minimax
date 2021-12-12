#include <iostream>
#include <fstream>
#include "tictactoe.h"

using namespace std;

#define ABOUT_PROJECT_FILE_PATHNAME "aboutTheProject.txt"

#define CLEAR_TERMINAL() system("clear || cls")

int main() {
    int programIsContinued = 1;

    while (programIsContinued) {
        CLEAR_TERMINAL();

        int menuChoice = 0;

        cout << "——— Tic Tac Toe With Minimax Algorithm ———\n" << endl;
        cout << "1- New Game\n2- About The Project\n3- Exit\n" << endl;
        cout << "Choice -> ";

        cin >> menuChoice;

        switch (menuChoice) {
            case 1: {
                CLEAR_TERMINAL();

                cout << "——— New Game ———\n" << endl;

                TicTacToe ticTacToe;

                CLEAR_TERMINAL();

                cout << "\nYou are -> " << ticTacToe.getPlayerSymbol() << endl; 
                cout << "Computer is -> " << ticTacToe.getComputerSymbol() << endl;
                cout << "\n" << (ticTacToe.getTurn() == ticTacToe.ROLE_PLAYER ? "You" : "The computer") << " will make the first move!\n" << endl; 

                while (!ticTacToe.gameIsEnded()) {
                    cout << string(40, '-') << endl;

                    if (ticTacToe.getTurn() == ticTacToe.ROLE_PLAYER) {
                        cout << "\nYour turn to move\n" << endl;

                        ticTacToe.renderTheView();

                        ticTacToe.move();

                        cout << "\nYou made your move, you can see the latest status of the game below.\n\n" << endl; 
                    }
                    else {
                        cout << "\nIt's time to move for the computer\n" << endl;

                        ticTacToe.move();

                        cout << "\nThe computer made its move, you can see the latest status of the game below.\n\n" << endl; 
                    }

                    ticTacToe.renderTheView();

                    cout << endl;
                }

                cout << string(40, '-') << endl;
                
                int winner = ticTacToe.whoIsWinner();

                if (winner == ticTacToe.WINNER_PLAYER)
                    cout << "\nYou are winner!\n\n" << "You can see the result of the game below.\n\n" << endl;
                else if (winner == ticTacToe.WINNER_COMPUTER)
                    cout << "\nComputer is winner, You are lost!\n\n" << "You can see the result of the game below.\n\n" << endl;
                else 
                    cout << "\nThe game ended in a draw!\n\n" << "You can see the result of the game below.\n\n" << endl;

                ticTacToe.renderTheView();

                cout << string(40, '-') << endl;

                cout << "\nDo you want to go back to the menu (1: Yes, 0: No) -> ";
                cin >> programIsContinued;

            } break;
            case 2: {
                CLEAR_TERMINAL();

                cout << "——— About The Project ———\n" << endl;

                ifstream inputFileStream;
                inputFileStream.open(ABOUT_PROJECT_FILE_PATHNAME);

                string line;

                while (getline(inputFileStream, line))
                    cout << line << endl;

                inputFileStream.close();

                cout << "\nDo you want to go back to the menu (1: Yes, 0: No) -> ";
                cin >> programIsContinued;

            } break;
            case 3:
                programIsContinued = false;

                break;
        }

    }

    return 0;
}
