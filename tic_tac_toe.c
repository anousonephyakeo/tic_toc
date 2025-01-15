#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 'X'
#define COMPUTER 'O'
#define EMPTY ' '

// Initialize the board with empty spaces and numbers for clarity
void initializeBoard(char board[3][3]) {
    int num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + num++;
        }
    }
}

// Display the Tic-Tac-Toe board with coordinates for easy reference
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Check if a player has won
int checkWinner(char board[3][3], char symbol) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return 1;
        }
    }
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return 1;
    }
    return 0;
}

// Check if the board is full (draw)
int isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != PLAYER && board[i][j] != COMPUTER) {
                return 0;
            }
        }
    }
    return 1;
}

// Handle the player's move
void playerMove(char board[3][3]) {
    int move;
    while (1) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        move--; // Adjust move to 0-based index

        int row = move / 3;
        int col = move % 3;

        if (move >= 0 && move < 9 && board[row][col] != PLAYER && board[row][col] != COMPUTER) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

// Find the best move for a symbol
int findBestMove(char board[3][3], char symbol, int *row, int *col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != PLAYER && board[i][j] != COMPUTER) {
                char temp = board[i][j];
                board[i][j] = symbol;
                if (checkWinner(board, symbol)) {
                    *row = i;
                    *col = j;
                    board[i][j] = temp;
                    return 1;
                }
                board[i][j] = temp;
            }
        }
    }
    return 0;
}

// Handle the computer's move
void computerMove(char board[3][3]) {
    int row, col;

    // Check if the computer can win in the next move
    if (findBestMove(board, COMPUTER, &row, &col)) {
        board[row][col] = COMPUTER;
        printf("Computer chose: %d\n", row * 3 + col + 1);
        return;
    }

    // Block the player's winning move
    if (findBestMove(board, PLAYER, &row, &col)) {
        board[row][col] = COMPUTER;
        printf("Computer chose: %d\n", row * 3 + col + 1);
        return;
    }

    // Choose a random empty spot
    srand(time(NULL));
    while (1) {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] != PLAYER && board[row][col] != COMPUTER) {
            board[row][col] = COMPUTER;
            printf("Computer chose: %d\n", row * 3 + col + 1);
            break;
        }
    }
}

// Main function to run the game
int main() {
    char board[3][3];
    int turn = 0; // 0 for player, 1 for computer

    initializeBoard(board);

    printf("Welcome to Tic-Tac-Toe!\n");
    displayBoard(board);

    while (1) {
        if (turn == 0) {
            printf("Your turn:\n");
            playerMove(board);
        } else {
            printf("Computer's turn:\n");
            computerMove(board);
        }

        displayBoard(board);

        if (checkWinner(board, PLAYER)) {
            printf("Congratulations! You win!\n");
            break;
        } else if (checkWinner(board, COMPUTER)) {
            printf("Computer wins! Better luck next time.\n");
            break;
        } else if (isDraw(board)) {
            printf("It's a draw!\n");
            break;
        }

        turn = 1 - turn; // Alternate turns
    }

    printf("Game over. Thanks for playing!\n");
    return 0;
}
