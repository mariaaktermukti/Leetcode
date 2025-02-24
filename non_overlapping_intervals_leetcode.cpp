#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) 
    {
        return a[1] < b[1];
    });

    int prev_end = intervals[0][1]; 
    int remove_count = 0;

    for (int i = 1; i < intervals.size(); ++i) 
    {
        if (intervals[i][0] < prev_end) 
        {
            ++remove_count;
        } 
        else 
        {
            prev_end = intervals[i][1];
        }
    }

    return remove_count;
}

int main() 
{
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the intervals (start and end):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = eraseOverlapIntervals(intervals);
    cout << "Minimum number of intervals to remove: " << result << endl;

    return 0;
}
