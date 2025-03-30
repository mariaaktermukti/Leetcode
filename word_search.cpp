#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word, int index, int r, int c) {
        if (index == word.size()) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index])
            return false;

        char temp = board[r][c];
        board[r][c] = '#'; // Mark as visited

        bool found = dfs(board, word, index + 1, r + 1, c) ||
                     dfs(board, word, index + 1, r - 1, c) ||
                     dfs(board, word, index + 1, r, c + 1) ||
                     dfs(board, word, index + 1, r, c - 1);

        board[r][c] = temp; // Restore original letter

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int m, n;
    cout << "Enter grid size (rows and columns): ";
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    cout << "Enter the board characters row by row:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cout << "Enter the word to search: ";
    cin >> word;

    Solution sol;
    if (sol.exist(board, word)) {
        cout << "Word exists in the board.\n";
    } else {
        cout << "Word does not exist in the board.\n";
    }

    return 0;
}
