#include <iostream>
using namespace std;

// Function to draw the Tic-Tac-Toe board 
void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check for a win 
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
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

// Function to check for a draw 
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Main function 
int main() {
    char choice;
    do {
        // Initialize the board and players 
        char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
        char player = 'X';
        int row, col;
        bool gameWon = false;

        cout << "Welcome to Tic-Tac-Toe!\n";

        // Game loop 
        while (true) {
            // Draw the board 
            drawBoard(board);

            // Prompt for valid input 
            while (true) {
                cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
                cin >> row >> col;

                if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                    cout << "Invalid move. Try again.\n";
                } else {
                    break; // Valid input, exit the loop.
                }
            }

            // Make the move 
            board[row][col] = player;

            // Check for a win after making a move 
            if (checkWin(board, player)) {
                drawBoard(board);
                cout << "Player " << player << " wins!\n";
                gameWon = true;
                break; // Exit the loop after a win.
            }

            // Check for a draw 
            if (checkDraw(board)) {
                drawBoard(board);
                cout << "It's a draw!\n";
                break; // Exit the loop after a draw.
            }

            // Switch to the other player 
            player = (player == 'X') ? 'O' : 'X';
        }

        // Ask if the players want to play another game 
        cout << "Do you want to play another game? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
