#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int start = 0, maxLength = 0, zeroCount = 0;

        for (int end = 0; end < nums.size(); ++end) 
        {
            if (nums[end] == 0) 
            {
                zeroCount++;
            }

            while (zeroCount > k) 
            {
                if (nums[start] == 0) 
                {
                    zeroCount--;
                }
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "Output: " << solution.longestOnes(nums1, k1) << endl; 

    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    cout << "Output: " << solution.longestOnes(nums2, k2) << endl; 

    return 0;
}
