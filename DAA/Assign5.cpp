#include <iostream>
#include <vector>
using namespace std;

// Function to print the chessboard
void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check this row on left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

// Recursive function to solve n-Queens problem
bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    // If all queens are placed, return true
    if (col >= n) return true;

    // Try placing this queen in all rows one by one
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; // Place queen

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1, n)) return true;

            board[i][col] = 0; // Backtrack and remove queen
        }
    }

    // If the queen can't be placed in any row in this column, return false
    return false;
}

// Function to initialize the board with the first queen
bool placeFirstQueen(vector<vector<int>>& board, int row, int col, int n) {
    if (row >= n || col >= n) return false; // Invalid position
    board[row][col] = 1; // Place the first queen
    return solveNQueens(board, col + 1, n); // Solve for remaining queens
}

int main() {
    int n;
    cout << "Enter the size of the board (n): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize n x n board with 0

    int row, col;
    cout << "Enter the row and column to place the first queen (0-based indexing): ";
    cin >> row >> col;

    if (!placeFirstQueen(board, row, col, n)) {
        cout << "Solution does not exist." << endl;
    } else {
        cout << "Solution:" << endl;
        printBoard(board, n);
    }

    return 0;
}
