#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int total = 0;
    for (int num : nums) total += num;

    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    bool result = canPartition(nums);

    if (result)
        cout << "True - Can be partitioned into equal sum subsets." << endl;
    else
        cout << "False - Cannot be partitioned into equal sum subsets." << endl;

    return 0;
}
