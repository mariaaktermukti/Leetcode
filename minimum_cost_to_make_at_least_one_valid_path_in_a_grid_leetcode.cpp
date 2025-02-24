#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; 

        pq.emplace(0, 0, 0);
        cost[0][0] = 0;

        while (!pq.empty()) {
            auto [curCost, x, y] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1) return curCost;

            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d][0], ny = y + directions[d][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nextCost = curCost + (grid[x][y] != d + 1 ? 1 : 0);
                    if (nextCost < cost[nx][ny]) {
                        cost[nx][ny] = nextCost;
                        pq.emplace(nextCost, nx, ny);
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> grid1 = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
    vector<vector<int>> grid2 = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
    vector<vector<int>> grid3 = {{1, 2}, {4, 3}};

    Solution solution;

    cout << "Minimum cost for grid1: " << solution.minCost(grid1) << endl; 
    cout << "Minimum cost for grid2: " << solution.minCost(grid2) << endl; 
    cout << "Minimum cost for grid3: " << solution.minCost(grid3) << endl; 

    return 0;
}
