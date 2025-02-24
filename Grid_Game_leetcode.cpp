#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) 
    {
        int n = grid[0].size();
        vector<long long> prefixTop(n, 0), prefixBottom(n, 0);

        prefixTop[0] = grid[0][0];
        prefixBottom[0] = grid[1][0];

        for (int i = 1; i < n; ++i) 
        {
            prefixTop[i] = prefixTop[i - 1] + grid[0][i];
            prefixBottom[i] = prefixBottom[i - 1] + grid[1][i];
        }

        long long totalTop = prefixTop[n - 1];
        long long totalBottom = prefixBottom[n - 1]; 

        long long minPointsRobot2 = LLONG_MAX;

        for (int i = 0; i < n; ++i)
        {
            long long pointsAbove = (i < n - 1) ? totalTop - prefixTop[i] : 0;
            long long pointsBelow = (i > 0) ? prefixBottom[i - 1] : 0;
            long long robot2Points = max(pointsAbove, pointsBelow);
            minPointsRobot2 = min(minPointsRobot2, robot2Points);
        }

        return minPointsRobot2;
    }
};

int main() 
{
    Solution solution;

    vector<vector<int>> grid1 = {{2, 5, 4}, {1, 5, 1}};
    cout << "Output for grid1: " << solution.gridGame(grid1) << endl;

    vector<vector<int>> grid2 = {{3, 3, 1}, {8, 5, 2}};
    cout << "Output for grid2: " << solution.gridGame(grid2) << endl;

    vector<vector<int>> grid3 = {{1, 3, 1, 15}, {1, 3, 3, 1}};
    cout << "Output for grid3: " << solution.gridGame(grid3) << endl;

    return 0;
}
