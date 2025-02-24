#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);
        int maxLength = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {

                int diff = abs(nums[i] - nums[j]);
                
                if (dp[j].count(diff))
                 {
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                } 
                else 
                {
                    dp[i][diff] = max(dp[i][diff], 2);
                }
                
                maxLength = max(maxLength, dp[i][diff]);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {16, 6, 3};
    cout << "Example 1 Output: " << sol.longestSubsequence(nums1) << endl; 

    vector<int> nums2 = {6, 5, 3, 4, 2, 1};
    cout << "Example 2 Output: " << sol.longestSubsequence(nums2) << endl; 

    vector<int> nums3 = {10, 20, 10, 19, 10, 20};
    cout << "Example 3 Output: " << sol.longestSubsequence(nums3) << endl; 

    return 0;
}
