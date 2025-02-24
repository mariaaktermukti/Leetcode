#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        
        unordered_map<int, pair<int, int>> valueToIndex;
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                valueToIndex[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rowPaintCount(m, 0);
        vector<int> colPaintCount(n, 0);
        
        int rowTarget = n, colTarget = m;
        
        for (int i = 0; i < arr.size(); ++i) 
        {
            auto [row, col] = valueToIndex[arr[i]];

            rowPaintCount[row]++;
            colPaintCount[col]++;

            if (rowPaintCount[row] == rowTarget || colPaintCount[col] == colTarget) 
            {
                return i;
            }
        }

        return -1;
    }
};

int main() 
{
    Solution solution;
    
    vector<int> arr1 = {1, 3, 4, 2};
    vector<vector<int>> mat1 = {{1, 4}, {2, 3}};
    cout << "Example 1 Output: " << solution.firstCompleteIndex(arr1, mat1) << endl;

    vector<int> arr2 = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat2 = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    cout << "Example 2 Output: " << solution.firstCompleteIndex(arr2, mat2) << endl;

    return 0;
}
