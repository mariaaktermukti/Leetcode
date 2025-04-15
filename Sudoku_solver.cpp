#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c || board[i][col] == c) return false;
        }

        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == c) return false;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter Sudoku board (use . for empty cells):\n";
    
    for (int i = 0; i < 9; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }

    Solution solver;
    solver.solveSudoku(board);

    cout << "\nSolved Sudoku:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
