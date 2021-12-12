#include "tictactoe.h"

char const TicTacToe::symbols[2] = {'X', 'O'};

TicTacToe::TicTacToe() {
    int selectedSymbol;
    int firstMoveTurn;

    cout << "Which symbol do you want to select (1: X, 2: 0) -> ";
    cin >> selectedSymbol;

    cout << "Who will make the first move (Me: 1, Computer: 2) -> ";
    cin >> firstMoveTurn;

    this->playerSymbol = symbols[selectedSymbol - 1];
    this->computerSymbol = selectedSymbol == 1 ? symbols[1] : symbols[0];

    this->turn = firstMoveTurn - 1;

    for (int i = 0; i < 9; i++)
        this->moves[i] = ' ';    

    this->totalMovement = 0;
    this->winner = 0;
}
char TicTacToe::getPlayerSymbol() const {
    return this->playerSymbol;
}

char TicTacToe::getComputerSymbol() const {
    return this->computerSymbol;
}

int TicTacToe::getTurn() const {
    return this->turn;
}

int TicTacToe::getTotalMovement() const {
    return this->totalMovement;
}

void TicTacToe::renderTheView() const {
    cout << moves[0] << " | " << moves[1] << " | " << moves[2] << endl;
    cout << "—————————" << endl;
    cout << moves[3] << " | " << moves[4] << " | " << moves[5] << endl;
    cout << "—————————" << endl;
    cout << moves[6] << " | " << moves[7] << " | " << moves[8] << "\n" << endl;
}

bool TicTacToe::gameIsEnded() {

    // Scorless 

    if (this->totalMovement == 9){
        winner = this->WINNER_SCORLESS;

        return true;
    }

    // Horizontal Control

    for (int i = 0; i < 7; i += 3) {
        if ((this->moves[i] == computerSymbol && this->moves[i + 1] == computerSymbol) && this->moves[i + 2] == computerSymbol) {
            this->winner = this->WINNER_COMPUTER;
            
            return true; 
        }
        else if ((this->moves[i] == playerSymbol && this->moves[i + 1] == playerSymbol) && this->moves[i + 2] == playerSymbol) {
            this->winner = this->WINNER_PLAYER;

            return true;
        }
    }

    // Vertical Control

    for (int i = 0; i < 3; i++) {
        if ((this->moves[i] == computerSymbol && this->moves[i + 3] == computerSymbol) && this->moves[i + 6] == computerSymbol) {
            this->winner = this->WINNER_COMPUTER;

            return true;
        }
        else if ((this->moves[i] == playerSymbol && this->moves[i + 3] == playerSymbol) && this->moves[i + 6] == playerSymbol) {
            this->winner = this->WINNER_PLAYER;

            return true;
        }
    }

    // Cross Control

    if ((this->moves[0] == computerSymbol && this->moves[4] == computerSymbol) && this->moves[8] == computerSymbol) {
        this->winner = this->WINNER_COMPUTER;

        return true;
    }
    else if ((this->moves[0] == playerSymbol && this->moves[4] == playerSymbol) && this->moves[8] == playerSymbol) {
        this->winner = this->WINNER_PLAYER;

        return true;
    }
    else if ((this->moves[2] == computerSymbol && this->moves[4] == computerSymbol) && this->moves[6] == computerSymbol){ 
        this->winner = this->WINNER_COMPUTER;

        return true;
    }
    else if ((this->moves[2] == playerSymbol && this->moves[4] == playerSymbol) && this->moves[6] == playerSymbol){ 
        this->winner = this->WINNER_PLAYER;

        return true;
    }

    return false;
}

int TicTacToe::whoIsWinner() const {
    return this->winner;
}

void TicTacToe::move() {
    int movement = 0;

    if (this->turn == this->ROLE_PLAYER) {
        while (true) {
            while (movement < 1 || movement > 9) {
                cout << "Please enter an index [1-9] -> ";
                cin >> movement;
            }

            if (this->moves[movement - 1] != ' ') {
                cout << "Index number " << movement << " is full!" << endl;

                movement = 0;
            }
            else 
                break;
        }

        this->moves[movement - 1] = this->playerSymbol;
        this->turn = this->ROLE_COMPUTER;
    }
    else {
        if (this->totalMovement == 0)
            movement = 0;
        else
            movement =  this->minimax(0);

        this->moves[movement] = this->computerSymbol;
        this->turn = this->ROLE_PLAYER;
    }

    totalMovement++;
}

int TicTacToe::minimax(int height) {
    // This condition was created to check if this function is a leaf.

    if (this->gameIsEnded()) { 
        int winner = this->whoIsWinner();

        return winner;
    }

    int returnFlag = height % 2;

    int numberOfTotalIndex = sizeof(this->moves) / sizeof(char);
    int scores[numberOfTotalIndex];

    for (int i = 0; i < numberOfTotalIndex; i++)
        scores[i] = -2;

    for (int i = 0; i < numberOfTotalIndex; i++) {
        if (this->moves[i] == ' ') {
            if (returnFlag == this->MAX)
                this->moves[i] = this->computerSymbol;
            else
                this->moves[i] = this->playerSymbol;

            this->totalMovement += 1;

            scores[i] = this->minimax(height + 1);
            moves[i] = ' ';

            this->totalMovement -= 1;
        }
    }
        
    // These conditions were created because this function is not a leaf.

    if (height == 0) 
        return distance(scores, max_element(scores, scores + numberOfTotalIndex)); // It gives an index of maximum value found in scores array
    else if (returnFlag == this->MAX) 
        return *max_element(scores, scores + numberOfTotalIndex); // It gives an maximum value found in scores array
    else {
        if (distance(scores, find(scores, scores + numberOfTotalIndex, -1)) < numberOfTotalIndex) // If this condition is true, it means the scores array contains the value -1.
            return -1;
        else
            return 0;
    }
}
