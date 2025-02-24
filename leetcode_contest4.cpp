#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        int n = nums.size();
        
        long long maxSum = nums[0];
        long long currentSum = nums[0];
        
        for (int i = 1; i < n; i++) {
            currentSum = max((long long)nums[i], currentSum + (long long)nums[i]);  
            maxSum = max(maxSum, currentSum);
        }

        vector<long long> prefixSum(n, 0), suffixSum(n, 0);
        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + nums[i];
        }

        unordered_map<int, vector<int>> elementPositions;
        for (int i = 0; i < n; i++) {
            elementPositions[nums[i]].push_back(i);
        }

        long long bestSum = maxSum; 
        
        for (auto& entry : elementPositions) {
            int value = entry.first;
            vector<int>& positions = entry.second;
            
            vector<long long> newPrefixSum(n, 0), newSuffixSum(n, 0);
            newPrefixSum[0] = (nums[0] == value) ? 0 : (long long)nums[0];  
            newSuffixSum[n - 1] = (nums[n - 1] == value) ? 0 : (long long)nums[n - 1]; 
            
            for (int i = 1; i < n; i++) {
                if (nums[i] != value) {
                    newPrefixSum[i] = newPrefixSum[i - 1] + (long long)nums[i]; 
                } else {
                    newPrefixSum[i] = newPrefixSum[i - 1]; 
                }
            }
            
            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] != value) {
                    newSuffixSum[i] = newSuffixSum[i + 1] + (long long)nums[i];  
                } else {
                    newSuffixSum[i] = newSuffixSum[i + 1];  
                }
            }
            
            long long newMaxSum = max(newPrefixSum[n - 1], newSuffixSum[0]);
            bestSum = max(bestSum, newMaxSum);
        }

        return bestSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-3, 2, -2, -1, 3, -2, 3};
    cout << "Example 1 Output: " << sol.maxSubarraySum(nums1) << endl;  

    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Example 2 Output: " << sol.maxSubarraySum(nums2) << endl; 

    return 0;
}
