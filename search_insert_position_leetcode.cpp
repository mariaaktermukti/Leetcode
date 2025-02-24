#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    
    Solution solution;
    
    cout << "Test case 1: " << solution.searchInsert(nums1, target1) << endl; 
    cout << "Test case 2: " << solution.searchInsert(nums2, target2) << endl; 
    cout << "Test case 3: " << solution.searchInsert(nums3, target3) << endl; 
    
    return 0;
}
