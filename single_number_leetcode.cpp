#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0; 
        for (int num : nums) {
            result ^= num; 
        }
        return result;
    }
};

#include <iostream>
int main() {
    Solution solution;

    vector<int> nums1 = {2, 2, 1};
    cout << "The single number in nums1 is: " << solution.singleNumber(nums1) << endl;

    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "The single number in nums2 is: " << solution.singleNumber(nums2) << endl;

    vector<int> nums3 = {1};
    cout << "The single number in nums3 is: " << solution.singleNumber(nums3) << endl;

    return 0;
}
