#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxPrefix(n, 0);
        
        maxPrefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxPrefix[i] = max(maxPrefix[i - 1], nums[i]);
        }
        
        long long maxValue = 0;
        for (int j = 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                long long tripletValue = (long long)(maxPrefix[j - 1] - nums[j]) * nums[k];
                maxValue = max(maxValue, tripletValue);
            }
        }
        
        return maxValue;
    }
};

int main() {
    vector<vector<int>> testCases = {
        {12, 6, 1, 2, 7}, 
        {1, 10, 3, 4, 19},  
        {1, 2, 3},          
        {5, 4, 3, 2, 1},    
        {2, 3, 10, 7, 1}  
    };
    
    Solution solution;
    
    for (int i = 0; i < testCases.size(); i++) {
        long long result = solution.maximumTripletValue(testCases[i]);
        cout << "Test Case " << i + 1 << ": " << result << endl;
    }
    
    return 0;
}
