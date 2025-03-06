#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the matrix elements:" << endl;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    sol.rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
