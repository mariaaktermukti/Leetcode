#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;

        while (num <= n * n) {
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++;

            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    Solution sol;
    vector<vector<int>> result = sol.generateMatrix(n);

    cout << "Spiral Matrix:\n";
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << "\n";
    }

    return 0;
}
