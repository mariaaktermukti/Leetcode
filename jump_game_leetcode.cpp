#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) 
        {
            if (i > maxReach) 
            {
                return false;  
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) 
            {
                return true;  
            }
        }
        
        return true;
    }
};

int main()
{
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    Solution solution;
    
    cout << "Can jump (Example 1): " << (solution.canJump(nums1) ? "true" : "false") << endl;
    cout << "Can jump (Example 2): " << (solution.canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
