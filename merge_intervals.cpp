#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]); 

        for (int i = 1; i < intervals.size(); i++) 
        {
            vector<int>& last = merged.back();
            if (intervals[i][0] <= last[1]) 
            { 
                last[1] = max(last[1], intervals[i][1]);
            } 
            else 
            {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

int main() 
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start end):" << endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution sol;
    vector<vector<int>> mergedIntervals = sol.merge(intervals);

    cout << "Merged Intervals: " << endl;
    for (const auto& interval : mergedIntervals) 
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
