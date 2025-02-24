#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        unordered_map<int, int> freq; 
        int operations = 0;

        for (int num : nums) 
        {
            int complement = k - num; 

           
            if (freq[complement] > 0) 
            {
                operations++;           
                freq[complement]--;    
            } 
            else 
            {
                freq[num]++;          
            }
        }

        return operations;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 5;
    cout << "Maximum operations for nums = [1, 2, 3, 4], k = 5: ";
    cout << solution.maxOperations(nums1, k1) << endl;

    vector<int> nums2 = {3, 1, 3, 4, 3};
    int k2 = 6;
    cout << "Maximum operations for nums = [3, 1, 3, 4, 3], k = 6: ";
    cout << solution.maxOperations(nums2, k2) << endl;
    
    vector<int> nums3 = {2, 4, 3, 5, 1};
    int k3 = 7;
    cout << "Maximum operations for nums = [2, 4, 3, 5, 1], k = 7: ";
    cout << solution.maxOperations(nums3, k3) << endl;

    return 0;
}
