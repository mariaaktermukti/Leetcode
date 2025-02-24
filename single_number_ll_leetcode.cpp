#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones; 
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 2, 3, 2};
    cout << "The single number in nums1 is: " << solution.singleNumber(nums1) << endl;

    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << "The single number in nums2 is: " << solution.singleNumber(nums2) << endl;

    vector<int> nums3 = {30000, 500, 100, 30000, 100, 30000, 100};
    cout << "The single number in nums3 is: " << solution.singleNumber(nums3) << endl;

    vector<int> nums4 = {7};
    cout << "The single number in nums4 is: " << solution.singleNumber(nums4) << endl;

    return 0;
}
