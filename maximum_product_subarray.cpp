#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxProd = nums[0], minProd = nums[0], result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(maxProd, minProd); 
            
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            
            result = max(result, maxProd);
        }
        
        return result;
    }
};

// Driver Code
int main() {
    Solution solution;
    
    vector<int> nums1 = {2, 3, -2, 4};
    cout << solution.maxProduct(nums1) << endl; 

    vector<int> nums2 = {-2, 0, -1};
    cout << solution.maxProduct(nums2) << endl; 

    vector<int> nums3 = {2, 3, -2, 4, -1};
    cout << solution.maxProduct(nums3) << endl; // Output: 48

    return 0;
}
