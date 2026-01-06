#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int num : nums) {
            vector<int> prev = dp;  
            for (int r = 0; r < 3; r++) {
                int s = prev[r] + num;
                dp[s % 3] = max(dp[s % 3], s);
            }
        }
        return dp[0];
    }
};

int main() {
    int n;
    cin >> n;               

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.maxSumDivThree(nums) << "\n";

    return 0;
}
