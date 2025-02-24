#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3};
    solution.nextPermutation(nums1);
    cout << "Next permutation: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    vector<int> nums2 = {3, 2, 1};
    solution.nextPermutation(nums2);
    cout << "Next permutation: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    vector<int> nums3 = {1, 1, 5};
    solution.nextPermutation(nums3);
    cout << "Next permutation: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;

    return 0;
}
