#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) 
    {
        double maxSum = 0;
        double currentSum = 0;
        for (int i = 0; i < k; ++i) 
        {
            currentSum += nums[i];
        }

        maxSum = currentSum;

        for (int i = k; i < nums.size(); ++i) 
        {
            currentSum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, currentSum);
        }
        return maxSum / k;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    std::cout << "Maximum Average for Example 1: " << sol.findMaxAverage(nums1, k1) << std::endl;

    std::vector<int> nums2 = {5};
    int k2 = 1;
    std::cout << "Maximum Average for Example 2: " << sol.findMaxAverage(nums2, k2) << std::endl;

    return 0;
}
