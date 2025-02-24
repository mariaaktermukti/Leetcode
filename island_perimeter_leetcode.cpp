#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int cnt;
    bool vis[105][105]; 
    vector<pair<int, int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n, m;

    bool valid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void dfs(int si, int sj, vector<vector<int>>& grid) {
        vis[si][sj] = true;
        
        for (int i = 0; i < 4; i++) {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (!valid(ci, cj) || grid[ci][cj] == 0) {
                cnt++; 
            } else if (!vis[ci][cj] && grid[ci][cj] == 1) {
                dfs(ci, cj, grid);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        cnt = 0;
        n = grid.size();
        m = grid[0].size();
        memset(vis, false, sizeof(vis)); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid);
                    return cnt; 
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    Solution sol;
    cout << "Island Perimeter: " << sol.islandPerimeter(grid) << endl;
    return 0;
}
