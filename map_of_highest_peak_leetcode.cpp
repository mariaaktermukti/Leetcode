#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1)); 
        queue<pair<int, int>> q;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (isWater[i][j] == 1) 
                {
                    height[i][j] = 0; 
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) 
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) 
            {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) 
                {
                    height[nx][ny] = height[x][y] + 1; 
                    q.push({nx, ny}); 
                }
            }
        }

        return height;
    }
};

int main() 
{
    Solution solution;
    vector<vector<int>> isWater = {{0, 1}, {0, 0}};
    vector<vector<int>> result = solution.highestPeak(isWater);

    cout << "Resulting Heights Matrix:" << endl;
    for (const auto& row : result) 
    {
        for (int height : row) 
        {
            cout << height << " ";
        }
        cout << endl;
    }

    return 0;
}
