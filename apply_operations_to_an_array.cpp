#include <iostream>
#include <vector>

using namespace std;

void applyOperations(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }


    vector<int> result(n);
    int index = 0;

    for (int num : nums) {
        if (num != 0) {
            result[index++] = num;
        }
    }

    nums = result;
}

int main() {
    vector<int> nums = {1, 2, 2, 1, 1, 0};

    applyOperations(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
