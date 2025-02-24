#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxArea = 0;
        int currentIsland = 2; 
        
        unordered_map<int, int> islandSize; 
        
        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};
        
        function<int(int, int, int)> dfs = [&](int x, int y, int id) {
            if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1) {
                return 0;
            }
            grid[x][y] = id; 
            int size = 1;
            for (int k = 0; k < 4; ++k) {
                size += dfs(x + dirX[k], y + dirY[k], id);
            }
            return size;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, currentIsland);
                    islandSize[currentIsland] = size;
                    maxArea = max(maxArea, size);
                    ++currentIsland;
                }
            }
        }

        if (maxArea == 0) return n * n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int area = 1; 
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dirX[k];
                        int nj = j + dirY[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1 && seen.count(grid[ni][nj]) == 0) {
                            seen.insert(grid[ni][nj]);
                            area += islandSize[grid[ni][nj]];
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
    cout << "Output for grid1: " << solution.largestIsland(grid1) << endl;

    vector<vector<int>> grid2 = {{1, 1}, {1, 0}};
    cout << "Output for grid2: " << solution.largestIsland(grid2) << endl;

    vector<vector<int>> grid3 = {{1, 1}, {1, 1}};
    cout << "Output for grid3: " << solution.largestIsland(grid3) << endl;

    return 0;
}
