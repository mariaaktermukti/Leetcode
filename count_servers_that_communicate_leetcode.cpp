#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j] == 1) 
                {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        
        int communicating_servers = 0;
        
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            
            {
                if (grid[i][j] == 1) 
                {
                    if (row_count[i] > 1 || col_count[j] > 1) 
                    {
                        communicating_servers++;
                    }
                }
            }
        }
        
        return communicating_servers;
    }
};

int main() 
{
    vector<vector<int>> grid =
    {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    Solution solution;
    int result = solution.countServers(grid);

    cout << "Number of servers that communicate: " << result << endl;

    return 0;
}
