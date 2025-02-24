#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int max1 = 0, max2 = 0; 
        
        for (int num : nums) 
        {
            if (num > max1) 
            {
                max2 = max1; 
                max1 = num;  
            } 
            else if (num > max2) 
            {
                max2 = num; 
            }
        }
        
        return (max1 - 1) * (max2 - 1); 
    }
};

int main() 
{
    Solution solution;

    vector<int> nums1 = {3, 4, 5, 2};
    cout << "Output for nums1: " << solution.maxProduct(nums1) << endl;

    vector<int> nums2 = {1, 5, 4, 5};
    cout << "Output for nums2: " << solution.maxProduct(nums2) << endl; 

    vector<int> nums3 = {3, 7};
    cout << "Output for nums3: " << solution.maxProduct(nums3) << endl; 

    return 0;
}
