#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            return a[1] < b[1];
        });

        int arrows = 0;       
        long lastArrow = LONG_MIN; 

        for (const auto& balloon : points) 
        {
            if (balloon[0] > lastArrow) 
            {
                ++arrows;         
                lastArrow = balloon[1];
            }
        }

        return arrows;
    }
};

int main() 
{
    Solution solution;

    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << "Example 1 Output: " << solution.findMinArrowShots(points1) << endl;

    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << "Example 2 Output: " << solution.findMinArrowShots(points2) << endl;

    vector<vector<int>> points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Example 3 Output: " << solution.findMinArrowShots(points3) << endl;

    return 0;
}
