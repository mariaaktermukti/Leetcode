#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int col = n - 1;

    while (row < m && col >= 0) 
    {
        if (matrix[row][col] == target) 
        {
            return true;
        } 
        else if (matrix[row][col] > target) 
        {
            col--;
        } 
        else 
        {
            row++;
        }
    }

    return false;
}

int main() 
{
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements row-wise (each row sorted):" << endl;
    for (int i = 0; i < m; ++i) 
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    bool found = searchMatrix(matrix, target);
    cout << (found ? "true" : "false") << endl;

    return 0;
}
