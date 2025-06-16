#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int xMin = nums[0];
        int maxD = -1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] <= xMin) {
                xMin = nums[i];
            } else {
                maxD = max(maxD, nums[i] - xMin);
            }
        }
        return maxD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n < 2) {
        cerr << "Invalid input. n should be at least 2.\n";
        return 1;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.maximumDifference(nums);
    cout << result << "\n";

    return 0;
}
