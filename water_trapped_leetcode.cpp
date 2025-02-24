#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        int waterTrapped = 0;
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!minHeap.empty()) {
            auto [height, x, y] = minHeap.top();
            minHeap.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    minHeap.push({max(height, heightMap[nx][ny]), nx, ny});
                }
            }
        }
        
        return waterTrapped;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> heightMap1 = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };
    cout << "Example 1: " << solution.trapRainWater(heightMap1) << endl;
    vector<vector<int>> heightMap2 = {
        {3, 3, 3, 3, 3},
        {3, 2, 2, 2, 3},
        {3, 2, 1, 2, 3},
        {3, 2, 2, 2, 3},
        {3, 3, 3, 3, 3}
    };
    cout << "Example 2: " << solution.trapRainWater(heightMap2) << endl;

    return 0;
}
