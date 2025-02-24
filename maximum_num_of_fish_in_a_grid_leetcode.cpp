#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int maxFish = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    int currentFish = dfs(grid, i, j);
                    maxFish = max(maxFish, currentFish);
                }
            }
        }
        
        return maxFish;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }
        
        int fish = grid[r][c];
        grid[r][c] = 0; 
        
        fish += dfs(grid, r + 1, c);
        fish += dfs(grid, r - 1, c);
        fish += dfs(grid, r, c + 1);
        fish += dfs(grid, r, c - 1);
        
        return fish;
    }
};

int main() {
    vector<vector<int>> grid1 = {
        {0, 2, 1, 0},
        {4, 0, 0, 3},
        {1, 0, 0, 4},
        {0, 3, 2, 0}
    };
    
    Solution solution;
    int result1 = solution.findMaxFish(grid1);
    cout << "Example 1 Output: " << result1 << endl; 

    vector<vector<int>> grid2 = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 1}
    };
    
    int result2 = solution.findMaxFish(grid2);
    cout << "Example 2 Output: " << result2 << endl; 

    return 0;
}