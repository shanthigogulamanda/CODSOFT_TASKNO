#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    char num = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void displayBoard() {
    cout << "\n";
    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "  " << board[i][0] << "  |  "
             << board[i][1] << "  |  "
             << board[i][2] << "\n";

        if (i < 2) {
            cout << "_____|_____|_____\n";
            cout << "     |     |     \n";
        }
    }
    cout << "     |     |     \n\n";
}

bool checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' &&
                board[i][j] <= '9')
                return false;
        }
    }
    return true;
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        char currentPlayer = 'X';
        bool gameOver = false;

        cout << "===== TIC-TAC-TOE GAME =====\n";
        cout << "Player 1: X\n";
        cout << "Player 2: O\n";
        cout << "Choose a position from 1 to 9.\n";

        while (!gameOver) {
            displayBoard();

            int position;
            cout << "Player " << currentPlayer
                 << ", enter your position (1-9): ";

            if (!(cin >> position)) {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (position < 1 || position > 9) {
                cout << "Invalid position! Choose from 1 to 9.\n";
                continue;
            }

            int row = (position - 1) / 3;
            int col = (position - 1) % 3;

            if (board[row][col] == 'X' ||
                board[row][col] == 'O') {
                cout << "That position is already taken!\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Congratulations! Player "
                     << currentPlayer << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer =
                    (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank you for playing Tic-Tac-Toe!\n";

    return 0;
}