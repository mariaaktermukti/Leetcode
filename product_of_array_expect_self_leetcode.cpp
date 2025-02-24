#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; ++i) 
        {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    for (int num : result1) cout << num << " ";
    cout << endl;

    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}
