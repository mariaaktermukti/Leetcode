#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int nonZeroIndex = 0;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] != 0) 
            {
                nums[nonZeroIndex++] = nums[i];  
            }
        }

        for (int i = nonZeroIndex; i < nums.size(); i++) 
        {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    cout << "Output: ";
    for (int num : nums1) 
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {0};
    solution.moveZeroes(nums2);
    cout << "Output: ";
    for (int num : nums2) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
