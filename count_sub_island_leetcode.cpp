#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vis[505][505];  
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  
    int n, m;
    bool flag;

    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    void dfs(int si, int sj, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vis[si][sj] = true;
        if (grid1[si][sj] == 0)
            flag = false;

        for (int i = 0; i < 4; i++) {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj] == 1)
                dfs(ci, cj, grid1, grid2);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        n = grid1.size();
        m = grid1[0].size();
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid2[i][j] == 1) {
                    flag = true;
                    dfs(i, j, grid1, grid2);
                    if (flag)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1}
    };

    vector<vector<int>> grid2 = {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0}
    };

    cout << "Number of sub-islands: " << sol.countSubIslands(grid1, grid2) << endl;

    return 0;
}
