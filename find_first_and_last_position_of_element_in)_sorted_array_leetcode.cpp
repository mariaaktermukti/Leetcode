#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = findBound(nums, target, true);
        int rightIndex = findBound(nums, target, false);
        return {leftIndex, rightIndex};
    }
    
private:
    int findBound(const vector<int>& nums, int target, bool isLeft) {
        int lo = 0, hi = nums.size() - 1;
        int bound = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) {
                bound = mid;
                if(isLeft)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else if(nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return bound;
    }
};

int main() {
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    Solution sol;
    vector<int> result1 = sol.searchRange(nums1, target1);
    cout << "Test case 1: [" << result1[0] << ", " << result1[1] << "]\n";

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = sol.searchRange(nums2, target2);
    cout << "Test case 2: [" << result2[0] << ", " << result2[1] << "]\n"; 

    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = sol.searchRange(nums3, target3);
    cout << "Test case 3: [" << result3[0] << ", " << result3[1] << "]\n"; 

    return 0;
}
