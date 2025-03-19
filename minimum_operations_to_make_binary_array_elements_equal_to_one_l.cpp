#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size();
    int operations = 0;

    for (int i = 0; i <= n - 3; i++) {
        if (nums[i] == 0) {
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            operations++;
        }
    }
    if (nums[n - 2] == 0 || nums[n - 1] == 0) {
        return -1;
    }

    return operations;
}

int main() {
    vector<int> nums = {0, 1, 1, 1, 0, 0}; 
    cout << "Output: " << minOperations(nums) << endl;

    vector<int> nums2 = {0, 1, 1, 1}; 
    cout << "Output: " << minOperations(nums2) << endl;

    return 0;
}
