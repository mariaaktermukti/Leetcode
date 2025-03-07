#include <iostream>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    
    // Directions for the 8 neighbors
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    // Use two temporary states:
    // 2 -> A live cell that will die
    // -1 -> A dead cell that will become live
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;

            // Count live neighbors
            for (auto& dir : directions) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && abs(board[ni][nj]) == 1) {
                    liveNeighbors++;
                }
            }

            // Apply the rules
            if (board[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    board[i][j] = 2; // Mark as dying
                }
            } else {
                if (liveNeighbors == 3) {
                    board[i][j] = -1; // Mark as reviving
                }
            }
        }
    }

    // Update the board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 2) board[i][j] = 0;   // Dead
            if (board[i][j] == -1) board[i][j] = 1;  // Live
        }
    }
}

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> board(m, vector<int>(n));

    cout << "Enter the board elements (0 for dead, 1 for alive):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    gameOfLife(board);

    cout << "Next Generation Board:\n";
    printBoard(board);

    return 0;
}
