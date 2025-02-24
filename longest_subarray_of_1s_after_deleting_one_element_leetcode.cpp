#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int start = 0, maxLength = 0, zeroCount = 0;

        for (int end = 0; end < nums.size(); ++end) 
        {
            if (nums[end] == 0) 
            {
                zeroCount++;
            }

            while (zeroCount > 1) 
            {
                if (nums[start] == 0) 
                {
                    zeroCount--;
                }
                start++;
            }
            maxLength = max(maxLength, end - start);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 1, 0, 1};
    cout << "Output: " << solution.longestSubarray(nums1) << endl; 

    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << "Output: " << solution.longestSubarray(nums2) << endl; 

    vector<int> nums3 = {1, 1, 1};
    cout << "Output: " << solution.longestSubarray(nums3) << endl; 

    return 0;
}
