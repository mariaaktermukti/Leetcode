#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); 
        vector<int> columns(n, 0); 
        vector<int> diag1(2*n-1, 0);
        vector<int> diag2(2*n-1, 0); 
        backtrack(0, n, board, result, columns, diag1, diag2);
        return result;
    }

    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result, 
                   vector<int>& columns, vector<int>& diag1, vector<int>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (columns[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;
            }
            board[row][col] = 'Q';
            columns[col] = 1;
            diag1[row - col + n - 1] = 1;
            diag2[row + col] = 1;
            backtrack(row + 1, n, board, result, columns, diag1, diag2);
            board[row][col] = '.';
            columns[col] = 0;
            diag1[row - col + n - 1] = 0;
            diag2[row + col] = 0;
        }
    }
};

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(n);

    cout << "Distinct solutions to the " << n << "-Queens puzzle:" << endl;
    for (const auto& board : result) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
