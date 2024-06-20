#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Connect4 {
    vector<vector<char>> board;
    int rows;
    int cols;
    int currentPlayer;

public:
    Connect4(int numRows, int numCols) : rows(numRows), cols(numCols), currentPlayer(1) {
        board.resize(numRows, vector<char>(numCols, '.'));
    }

    void printBoard() {
        for (int i = 0; i < rows; i++) {
            cout << endl;
            for (int j = 0; j < cols; j++) {
                cout << board[i][j] << ' ';
            }
        }
        cout << endl;
        for (int i = 0; i < cols; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

    bool isValidMove(int col) {
        return col >= 0 && col < cols && board[0][col] == '.';
    }

    bool makeMove(int col, char token) {
        if (isValidMove(col)) {
            for (int i = rows - 1; i >= 0; i--) {
                if (board[i][col] == '.') {
                    board[i][col] = token;
                    return true;
                }
            }
        }
        return false;
    }

    bool isFull() {
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == '.') return false;
        }
        return true;
    }

    bool checkWin(char token) {
        // Check horizontal, vertical, and both diagonal directions
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == token) {
                    if (j + 3 < cols && board[i][j + 1] == token && board[i][j + 2] == token && board[i][j + 3] == token)
                        return true;
                    if (i + 3 < rows && board[i + 1][j] == token && board[i + 2][j] == token && board[i + 3][j] == token)
                        return true;
                    if (i + 3 < rows && j + 3 < cols && board[i + 1][j + 1] == token && board[i + 2][j + 2] == token && board[i + 3][j + 3] == token)
                        return true;
                    if (i + 3 < rows && j - 3 >= 0 && board[i + 1][j - 1] == token && board[i + 2][j - 2] == token && board[i + 3][j - 3] == token)
                        return true;
                }
            }
        }
        return false;
    }

    void switchPlayer() {
        currentPlayer = 3 - currentPlayer;
    }

    int minimax(int depth, bool isMaximizing) {
        if (checkWin('O')) return 10 - depth;
        if (checkWin('X')) return depth - 10;
        if (isFull()) return 0;

        if (isMaximizing) {
            int bestScore = numeric_limits<int>::min();
            for (int j = 0; j < cols; j++) {
                if (isValidMove(j)) {
                    makeMove(j, 'O');
                    int score = minimax(depth + 1, false);
                    board[0][j] = '.'; // Undo move
                    bestScore = max(bestScore, score);
                }
            }
            return bestScore;
        } else {
            int bestScore = numeric_limits<int>::max();
            for (int j = 0; j < cols; j++) {
                if (isValidMove(j)) {
                    makeMove(j, 'X');
                    int score = minimax(depth + 1, true);
                    board[0][j] = '.'; // Undo move
                    bestScore = min(bestScore, score);
                }
            }
            return bestScore;
        }
    }

    int getBestMove() {
        int bestScore = numeric_limits<int>::min();
        int move = -1;
        for (int j = 0; j < cols; j++) {
            if (isValidMove(j)) {
                makeMove(j, 'O');
                int score = minimax(0, false);
                board[0][j] = '.'; // Undo move
                if (score > bestScore) {
                    bestScore = score;
                    move = j;
                }
            }
        }
        return move;
    }

    void playGame() {
        char playAgain = 'y';
        while (playAgain == 'y' || playAgain == 'Y') {
            board = vector<vector<char>>(rows, vector<char>(cols, '.'));
            currentPlayer = 1;
            while (!isFull() && !checkWin('X') && !checkWin('O')) {
                printBoard();
                int move;
                if (currentPlayer == 1) {
                    cout << "Player " << currentPlayer << " turn (1-" << cols << "): ";
                    cin >> move;
                    move--;
                } else {
                    move = getBestMove();
                    cout << "AI chose column " << move + 1 << endl;
                }
                if (makeMove(move, currentPlayer == 1 ? 'X' : 'O')) {
                    if (checkWin(currentPlayer == 1 ? 'X' : 'O')) {
                        printBoard();
                        cout << "Player " << currentPlayer << " wins!" << endl;
                        break;
                    }
                    switchPlayer();
                } else {
                    cout << "Invalid move. Try again." << endl;
                }
            }
            if (isFull() && !checkWin('X') && !checkWin('O')) {
                cout << "It's a tie!" << endl;
            }
            cout << "Play again? (y/n): ";
            cin >> playAgain;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    Connect4 game(rows, cols);
    game.playGame();

    return 0;
}