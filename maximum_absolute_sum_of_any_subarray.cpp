#include <iostream>
#include <vector>
#include <algorithm> 

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int max_abs_sum = 0;
        int max_ending_here = 0;
        int min_ending_here = 0;
        
        for (int num : nums) {
            max_ending_here = std::max(num, max_ending_here + num);
            min_ending_here = std::min(num, min_ending_here + num);
            max_abs_sum = std::max(max_abs_sum, std::max(abs(max_ending_here), abs(min_ending_here)));
        }
        
        return max_abs_sum;
    }
};

int main() {
    std::vector<int> nums = {1, -3, 2, 3, -4}; 
    Solution sol;
    int result = sol.maxAbsoluteSum(nums);
    std::cout << "Maximum Absolute Sum of Any Subarray: " << result << std::endl;
    return 0;
}
