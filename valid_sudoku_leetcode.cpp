#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet, colSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (colSet.count(board[j][i])) return false;
                    colSet.insert(board[j][i]);
                }
            }
        }

        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                unordered_set<char> boxSet;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char curr = board[boxRow * 3 + i][boxCol * 3 + j];
                        if (curr != '.') {
                            if (boxSet.count(curr)) return false;
                            boxSet.insert(curr);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

int main() {
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>> board2 = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solution;
    
    cout << "Example 1 - isValidSudoku: " << (solution.isValidSudoku(board1) ? "true" : "false") << endl; 
    cout << "Example 2 - isValidSudoku: " << (solution.isValidSudoku(board2) ? "true" : "false") << endl; 

    return 0;
}
