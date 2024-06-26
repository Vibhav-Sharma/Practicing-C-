#include <iostream>
using namespace std;

void print_board(char board[3][3]) {                                                  //creating a 3*3 matrix for tic tac toe
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "  ";
        }
        cout << endl;
        if (i < 2) cout << endl;
    }
}

bool check_win(char board[3][3], char player) {                                                    //defining ways to win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool check_draw(char board[3][3]) {                                                               // Defining draw condition
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void update_board(char board[3][3], int row, int col, char player) {                          // Board updator
    board[row][col] = player;
}

void reset_board(char board[3][3]) {
    char initial_board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = initial_board[i][j];
        }
    }
}

int main() {
    char board[3][3];
    bool play_again = true;

    while (play_again) {
        reset_board(board);
        bool game_over = false;
        char current_player = 'X';

        while (!game_over) {
            cout << "Current board:\n";
            print_board(board);

            int move;
            cout << "Player " << current_player << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "Please enter a number between 1 and 9.\n";
                continue;
            }

            int row = (move - 1) / 3;                                   // the quitient gives the row
            int col = (move - 1) % 3;                                   // the remainder gives the column

            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Aiyen!, try again\n";
                continue;
            }

            update_board(board, row, col, current_player);

            if (check_win(board, current_player)) {
                cout << "Player " << current_player << " wins! :)\n";
                game_over = true;
            } else if (check_draw(board)) {
                cout << "It's a draw!\n";
                game_over = true;
            }

            current_player = (current_player == 'X') ? 'O' : 'X';
        }

        cout << "Final board:\n";
        print_board(board);

        char r;
        cout << "Do you wanna play again? (y/n): ";
        cin >> r;
        play_again = (r == 'y');
        if (r == 'n'){
            cout << "Thanks for playing!";
        }
    }
    return 0;                                              //if no return statement then it will generate enless loop
}
