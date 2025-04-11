#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    for (int row = n - 2; row >= 0; --row) {
        for (int col = 0; col < triangle[row].size(); ++col) {
            triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
        }
    }
    return triangle[0][0]; 
}

int main() {
    int n;
    cout << "Enter number of rows in the triangle: ";
    cin >> n;

    vector<vector<int>> triangle(n);
    cout << "Enter the triangle values row by row:\n";
    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    int result = minimumTotal(triangle);
    cout << "Minimum path sum from top to bottom is: " << result << endl;

    return 0;
}
