#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; 
        
        int sum = 0, count = 0;
        
        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << solution.subarraySum(nums, k) << endl;
    return 0;
}
