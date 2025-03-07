#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowHasZero = false, firstColHasZero = false;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0; 
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowHasZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstColHasZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
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

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout << "Modified Matrix:\n";
    printMatrix(matrix);

    return 0;
}
