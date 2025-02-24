#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) return 0; 

        int jumps = 0, maxReach = 0, currentEnd = 0;

        for (int i = 0; i < n - 1; i++) 
        {
            maxReach = max(maxReach, i + nums[i]);

            if (i == currentEnd) 
            {  
                jumps++;
                currentEnd = maxReach;

                if (currentEnd >= n - 1) 
                {
                    break; 
                }
            }
        }
        return jumps;
    }
};

int main() 
{
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {2, 3, 0, 1, 4};

    Solution solution;
    
    cout << "Minimum jumps (Example 1): " << solution.jump(nums1) << endl;
    cout << "Minimum jumps (Example 2): " << solution.jump(nums2) << endl;

    return 0;
}
