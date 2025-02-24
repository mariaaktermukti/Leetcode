#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                if (currentSum < target) {
                    ++left;
                } else if (currentSum > target) {
                    --right;
                } else {
                    return currentSum;
                }
            }
        }
        return closestSum;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    std::cout << "Closest Sum: " << solution.threeSumClosest(nums, target) << std::endl;
    return 0;
}
