#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    int n;
    cout << "Enter n (array size will be n+1): ";
    cin >> n;

    vector<int> nums(n + 1);
    cout << "Enter " << n + 1 << " elements (in range 1 to " << n << "): ";
    for (int i = 0; i <= n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    int duplicate = sol.findDuplicate(nums);

    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}
