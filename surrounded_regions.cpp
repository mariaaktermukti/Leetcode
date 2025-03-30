#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rows, cols;

    // DFS function to mark non-surrounded 'O's
    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O')
            return;

        board[r][c] = '#'; // Temporarily mark as non-surrounded

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        // Step 1: Mark all 'O's connected to the boundary
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j);
        }

        // Step 2: Replace all remaining 'O's with 'X', and revert '#' to 'O'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X'; // Captured region
                else if (board[i][j] == '#') board[i][j] = 'O'; // Restore non-surrounded region
            }
        }
    }
};

// Main function to take input and test the solution
int main() {
    int m, n;
    cout << "Enter board size (rows and columns): ";
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    cout << "Enter the board row by row (X and O only):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    Solution sol;
    sol.solve(board);

    cout << "Captured board:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
