#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Starting point
    if (obstacleGrid[0][0] == 1) return 0;
    dp[0][0] = 1;

    // Fill first column
    for (int i = 1; i < m; ++i)
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;

    // Fill first row
    for (int j = 1; j < n; ++j)
        dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;

    // Fill the rest
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid (0 for space, 1 for obstacle):\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    int result = uniquePathsWithObstacles(grid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
