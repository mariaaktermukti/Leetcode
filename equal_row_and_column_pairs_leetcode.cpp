#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct VectorHash 
{
    size_t operator()(const vector<int>& v) const 
    {
        size_t hash = 0;
        for (int num : v) 
        {
            hash ^= hash * 31 + num;
        }
        return hash;
    }
};

class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        unordered_map<vector<int>, int, VectorHash> rowMap;
        int n = grid.size();
        for (const auto& row : grid) 
        {
            rowMap[row]++;
        }

        int count = 0;
        for (int col = 0; col < n; col++) 
        {
            vector<int> column;
            for (int row = 0; row < n; row++) 
            {
                column.push_back(grid[row][col]);
            }
            if (rowMap.find(column) != rowMap.end()) 
            {
                count += rowMap[column];
            }
        }

        return count;
    }
};

int main() 
{
    Solution solution;
    vector<vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    cout << "Number of equal row and column pairs: " << solution.equalPairs(grid) << endl;
    return 0;
}
