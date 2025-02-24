#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target)
                return mid;
            
            if (nums[left] <= nums[mid]) { 
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else { 
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    int result1 = solution.search(nums1, target1);
    cout << "Example 1: Index of " << target1 << " in nums1 is " << result1 << "\n";
    
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    int result2 = solution.search(nums2, target2);
    cout << "Example 2: Index of " << target2 << " in nums2 is " << result2 << "\n";
    
    vector<int> nums3 = {1};
    int target3 = 0;
    int result3 = solution.search(nums3, target3);
    cout << "Example 3: Index of " << target3 << " in nums3 is " << result3 << "\n";
    
    return 0;
}
