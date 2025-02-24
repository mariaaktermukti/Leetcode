#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int xorNums1 = 0, xorNums2 = 0;

        for (int num : nums1) {
            xorNums1 ^= num;
        }

        for (int num : nums2) 
        {
            xorNums2 ^= num;
        }

        int result = 0;
        if (nums1.size() % 2 == 1) 
        {
            result ^= xorNums2; 
        }
        if (nums2.size() % 2 == 1) 
        {
            result ^= xorNums1; 
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    cout << "Output: " << solution.xorAllNums(nums1, nums2) << endl; 

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Output: " << solution.xorAllNums(nums1, nums2) << endl;

    return 0;
}
