#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, maxLength = 0, or_mask = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((or_mask & nums[right]) != 0) {  
                or_mask ^= nums[left];  
                left++;
            }
            or_mask |= nums[right];  
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 3, 8, 48, 10};
    cout << "Output for [1, 3, 8, 48, 10]: " << solution.longestNiceSubarray(nums1) << endl; 

    vector<int> nums2 = {3, 1, 5, 11, 13};
    cout << "Output for [3, 1, 5, 11, 13]: " << solution.longestNiceSubarray(nums2) << endl;

    return 0;
}
